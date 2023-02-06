#include <iostream>
#include <string>
#include <windows.h>
#include "Capgemini.h"

// Main function - Getting data from user/passing it to functions
int main()
{
    // initialize main variables
    int Working = 1,Program = 0;
    StoredPhones Warehouse1;
    // main loop
    while (Working)
    {
        // show main menu
        menu(0);
        // get main menu option
        std::cin>>Program;
        // handling user input
        // for 0 turn off program
        if (Program == 0)
        {
            std::cout << "Turning off the program...";
            Working = 0;
        }
        // for 1 add phone to warehouse
        else if (Program == 1)
        {
            // Get new phone data
            Phone Tmp;
            std::cout<<"Pass the Phone Brand name: ";
            std::cin>>Tmp.Brand;
            std::cout << "Pass the Phone Model name: ";
            std::cin >> Tmp.Model;
            std::cout << "Pass the Phone Form factor (x:y): ";
            std::cin >> Tmp.FormFactor;
            std::cout << "Pass the Phone Year of issue: ";
            std::cin >> Tmp.YearOfIssue;
            std::cout << "Pass the Phone Screen size (in inches): ";
            std::cin >> Tmp.ScreenSize;
            std::cout << "Pass the Phone Price: ";
            std::cin >> Tmp.Price;
            // if some of data is wrong type tell user it's wrong
            if (std::cin.fail())
            {
                std::cout << "Please enter a valid data" << std::endl;
                std::cin.clear();
                std::cin.ignore(80, '\n');
            }
            // else add to warehouse new phone
            else
                Warehouse1.Add(Tmp);
        }
        // for 2 delete phone from warehouse
        else if (Program == 2)
        {
            // Get phone to delete id
            int Tmp;
            std::cout << "Pass the Phone Id you want to delete: ";
            std::cin >> Tmp;
            // if some of data is wrong type tell user it's wrong
            if (std::cin.fail())
            {
                std::cout << "Please enter a valid integer" << std::endl;
                std::cin.clear();
                std::cin.ignore(80, '\n');
            }
            // else delete from warehouse selected phone
            else
                Warehouse1.Delete(Tmp);
        }
        // for 3 open report menu
        else if (Program == 3)
        {
            // show reports menu options
            menu(1);
            // Get option user wants to show
            int Tmp;
            std::cin>>Tmp;
            // if some of data is wrong type tell user it's wrong
            if (std::cin.fail())
            {
                std::cout << "Please enter a valid integer" << std::endl;
                std::cin.clear();
                std::cin.ignore(80, '\n');
            }
            // else show report
            else
            {
                // if selected 1-5 show report
                if (Tmp > 0 && Tmp < 6)
                    Warehouse1.Report(Tmp);
                // if selected 0 back to main menu
                else if (Tmp == 0)
                    continue;
                // else show error, not an option
                else
                {
                    std::cout << "an error occured, turning off the program...";
                    Working = 0;
                }
            }
        }
        // for other wrong data, turn of program
        else
        {
            std::cout<<"an error occured, turning off the program...";
            Working = 0;
        }

    }
    return 0;
}

// Function to show options
void menu(int Id)
{
    system("cls");
    if(Id == 0)
    {
        std::cout << "Welcome to the cell phone shop warehouse\n";
        std::cout << "Please insert wanted option:\n";
        std::cout << "[1]-for adding phone to warehouse\n";
        std::cout << "[2]-for deleting phone from warehouse\n";
        std::cout << "[3]-for show reports options\n";
        std::cout << "[0]-for exit the program\n";
        std::cout << "\n";
    }
    else if (Id == 1)
    {
        std::cout << "Choose on of the report option:\n";
        std::cout << "[1]-for show all phones by the same brand\n";
        std::cout << "[2]-for show all phones of a given form factor and screen size\n";
        std::cout << "[3]-for show the name of the brand with the maximum quantity of the phones\n";
        std::cout << "[4]-for show TOP-3 screen sizes (popularity is determined by the number of phones with the screen size)\n";
        std::cout << "[5]-for show all phones\n";

        std::cout << "[0]-for exit reports\n";
        std::cout << "\n";
    }
}

// Adding new phone to warehouse
void StoredPhones::Add(Phone NewPhone)
{
    // Checking if there is any phone in warehouse
    // if no, creating new table to add phone
    if (Phones == nullptr && Size == 0)
    {
        Size++;
        Phones = new Phone[Size];
        Phones[0] = NewPhone;
    }
    // if yes relocating table to add next phone
    else
    {
        Size++;
        Phone* Tmp = new Phone[Size];
        for (int i = 0; i < Size - 1; i++)
        {
            Tmp[i] = Phones[i];
        }
        Tmp[Size - 1] = NewPhone;
        delete[] Phones;
        Phones = Tmp;
    }
}

// Deleting phone from warehouse
void StoredPhones::Delete(int Id)
{
    // checking is the Id is in warehouse
    // if no show error
    if (Id > Size - 1)
    {
        std::cout << "Wrong Id!\n";
        system("pause");
    }
    // if yes delete from warehouse
    else
    {
        // if the phone is the only one clear warehouse
        if (Size == 1)
        {
            Size--;
            delete[] Phones;
        }
        // else relocate data to new, bigger array
        else
        {
            Size--;
            Phone* Tmp = new Phone[Size];
            for (int i = 0, j = 0; i < Size + 1; i++, j++)
            {
                if (i == Id)
                {
                    j--;
                    continue;
                }
                Tmp[j] = Phones[i];
            }
            delete[] Phones;
            Phones = Tmp;
        }
    }
}

// Reporting chosen option
void StoredPhones::Report(int Type)
{   
    // Show all phones by the same brand
    if (Type == 1)
    {
        // implement temporary variables
        std::string* Brands = nullptr;
        int BrandsSize = 0;
        // Getting the brands from warehouse array
        for (int i = 0; i < Size; i++)
        {
            // if first element create array
            if (BrandsSize == 0)
            {
                BrandsSize++;
                Brands = new std::string[BrandsSize];
                Brands[0] = Phones[i].Brand;
            }
            // else check if the brand exist in array and if not relocate array to add new element
            else
            {
                bool IsNew = true;
                for (int j = 0; j < BrandsSize; j++)
                {
                    if (Brands[j] == Phones[i].Brand)
                        IsNew = false;
                }
                if (IsNew)
                {
                    BrandsSize++;
                    std::string* Tmp = new std::string[BrandsSize];
                    for (int j = 0; j < BrandsSize - 1; j++)
                    {
                        Tmp[j] = Brands[j];
                    }
                    Tmp[BrandsSize - 1] = Phones[i].Brand;
                    delete[] Brands;
                    Brands = Tmp;
                }
            }
        }
        // show phones sorted by brands
        for (int i = 0; i < BrandsSize; i++)
        {
            std::cout << std::endl << Brands[i] << ": \n";
            for (int j = 0; j < Size; j++)
            {
                if (Brands[i] == Phones[j].Brand)
                    std::cout << "Id: " << j << ", Brand Name: " << Phones[j].Brand << ", Model name:" << Phones[j].Model << ", Form factor: " << Phones[j].FormFactor << ", Year of issue: " << Phones[j].YearOfIssue << ", Screen Size: " << Phones[j].ScreenSize << ", Price: " << Phones[j].Price << std::endl;
            }
        }
    }

    // Show all phones of a given form factor and screen size
    else if (Type == 2)
    {
        // Get variables to check from user
        std::string FormFactor;
        double ScreenSize;
        std::cout << "Pass Form factor (x:y): ";
        std::cin >> FormFactor;
        std::cout << "Pass Screen size (in inches): ";
        std::cin >> ScreenSize;

        // if some of data is wrong type tell user it's wrong
        if (std::cin.fail())
        {
            std::cout << "Please enter a valid data" << std::endl;
            std::cin.clear();
            std::cin.ignore(80, '\n');
        }
        // else show all phones that data match
        else {
            for (int i = 0; i < Size; i++)
            {
                if (FormFactor == Phones[i].FormFactor && ScreenSize == Phones[i].ScreenSize)
                    std::cout << "Id: " << i << ", Brand Name: " << Phones[i].Brand << ", Model name:" << Phones[i].Model << ", Form factor: " << Phones[i].FormFactor << ", Year of issue: " << Phones[i].YearOfIssue << ", Screen Size: " << Phones[i].ScreenSize << ", Price: " << Phones[i].Price << std::endl;
            }
        }

    }
    // Show the name of the brand with the maximum quantity of the phones
    else if (Type == 3)
    {
        // implement temporary variables
        std::string* Brands = nullptr;
        int BrandsSize = 0, * BrandsCount = nullptr, Max = 0, MaxIndex;
        // Count quantity of every brand
        for (int i = 0; i < Size; i++)
        {
            // if there is no brand in temp variable, create array and add first
            if (BrandsSize == 0)
            {
                BrandsSize++;
                Brands = new std::string[BrandsSize];
                BrandsCount = new int[BrandsSize];
                Brands[0] = Phones[i].Brand;
                BrandsCount[0] = 1;
            }
            // else check is it new
            else {
                bool IsNew = true;
                // if the variable isn't new increment count
                for (int j = 0; j < BrandsSize; j++)
                {
                    if (Phones[i].Brand == Brands[j])
                    {
                        IsNew = false;
                        BrandsCount[j]++;
                        break;
                    }
                }
                // if the variable is new relocate array to add new brand and set count for this brand to 1
                if (IsNew)
                {
                    BrandsSize++;
                    std::string* Tmp = new std::string[BrandsSize];
                    int* Tmp1 = new int[BrandsSize];
                    for (int j = 0; j < BrandsSize - 1; j++)
                    {
                        Tmp[j] = Brands[j];
                        Tmp1[j] = BrandsCount[j];

                    }
                    Tmp[BrandsSize - 1] = Phones[i].Brand;
                    Tmp1[BrandsSize - 1] = 1;

                    delete[] Brands;
                    Brands = Tmp;

                    delete[] BrandsCount;
                    BrandsCount = Tmp1;
                }
            }
        }
        // get brand that repeat most times
        for (int i = 0; i < BrandsSize; i++)
        {
            if (BrandsCount[i] > Max)
            {
                Max = BrandsCount[i];
                MaxIndex = i;
            }
        }
        // show most quantity brand
        if (Brands != nullptr)
            std::cout << "Most quantity has: " << Brands[MaxIndex] << ", with amount of: " << Max << std::endl;
    }
    //Show TOP - 3 screen sizes(popularity is determined by the number of phones with the screen size)
    else if (Type == 4)
    {
        // implement temporary variables
        double* ScreenSizes = nullptr;
        int ScreenSizesSize = 0, * ScreenSizesCount = nullptr, Max[3] = { 0,0,0 }, MaxIndex[3] = { 0,0,0 };

        // Count quantity of every screen sizes
        for (int i = 0; i < Size; i++)
        {
            // if there is no screen size in temp variable, create array and add first
            if (ScreenSizesSize == 0)
            {
                ScreenSizesSize++;
                ScreenSizes = new double[ScreenSizesSize];
                ScreenSizesCount = new int[ScreenSizesSize];
                ScreenSizes[0] = Phones[i].ScreenSize;
                ScreenSizesCount[0] = 1;
            }
            // else check is it new
            else {
                bool IsNew = true;
                // if the variable isn't new increment count
                for (int j = 0; j < ScreenSizesSize; j++)
                {
                    if (Phones[i].ScreenSize == ScreenSizes[j])
                    {
                        IsNew = false;
                        ScreenSizesCount[j]++;
                        break;
                    }
                }
                // if the variable is new relocate array to add new screen size and set count for this screen size to 1
                if (IsNew)
                {
                    ScreenSizesSize++;
                    double* Tmp = new double[ScreenSizesSize];
                    int* Tmp1 = new int[ScreenSizesSize];
                    for (int j = 0; j < ScreenSizesSize - 1; j++)
                    {
                        Tmp[j] = ScreenSizes[j];
                        Tmp1[j] = ScreenSizesCount[j];

                    }
                    Tmp[ScreenSizesSize - 1] = Phones[i].ScreenSize;
                    Tmp1[ScreenSizesSize - 1] = 1;

                    delete[] ScreenSizes;
                    ScreenSizes = Tmp;

                    delete[] ScreenSizesCount;
                    ScreenSizesCount = Tmp1;
                }
            }
        }
        
        // get 3 screen sizes that repeat most times
        for (int i = 0; i < ScreenSizesSize; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (ScreenSizesCount[i] > Max[j])
                {
                    // if j == 0 move position 0 to 1, and 1 to 2
                    if (j == 0)
                    {
                        Max[2] = Max[1];
                        Max[1] = Max[0];
                        MaxIndex[2] = MaxIndex[1];
                        MaxIndex[1] = MaxIndex[0];
                    }
                    // if j == 1 move position and 1 to 2

                    else if (j == 1)
                    {
                        Max[2] = Max[1];
                        MaxIndex[2] = MaxIndex[1];
                    }
                    // add max to current position
                    Max[j] = ScreenSizesCount[i];
                    MaxIndex[j] = i;
                    break;

                }
            }

        }
        // show top 3 screen sizes
        if (ScreenSizes != nullptr)
            std::cout << "Top 3 is: " << ScreenSizes[MaxIndex[0]] << ", " << ScreenSizes[MaxIndex[1]] << ", " << ScreenSizes[MaxIndex[2]] << std::endl;
    }
    // Show all phones in warehouse
    else if (Type == 5)
    {
        std::cout << "Full phones list:\n";
        for (int i = 0; i < Size; i++)
        {
            std::cout << "Id: " << i << ", Brand Name: " << Phones[i].Brand << ", Model name:" << Phones[i].Model << ", Form factor: " << Phones[i].FormFactor << ", Year of issue: " << Phones[i].YearOfIssue << ", Screen Size: " << Phones[i].ScreenSize << ", Price: " << Phones[i].Price << std::endl;
        }
    }
    // Pause for every report
    system("pause");
}
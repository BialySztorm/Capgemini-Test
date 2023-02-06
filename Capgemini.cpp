#include <iostream>
#include <string>
#include <windows.h>

struct Phone {
    std::string Brand;
    std::string Model;
    std::string FormFactor;
    int YearOfIssue;
    double ScreenSize;
    double Price;
};

class StoredPhones {
    Phone *Phones = nullptr;
    int Size = 0;
    public:
        void Add(Phone NewPhone)
        {
            if (Phones == nullptr && Size == 0)
            {
                Size++;
                Phones = new Phone[Size];
                Phones[0] = NewPhone;
            }
            else
            {
                Size++;
                Phone* Tmp = new Phone[Size];
                for (int i = 0; i < Size - 1; i++)
                {
                    Tmp[i] = Phones[i];
                }
                Tmp[Size-1] = NewPhone;
                delete[] Phones;
                Phones = Tmp;
            }
        }
        void Delete(int Id)
        {
            if (Id > Size-1)
            {
                std::cout<<"Wrong Id!\n";
                system("pause");
            }
            else
            {
                if (Size == 1)
                {
                    Size --;
                    delete [] Phones;
                }
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
        void Report(int Type)
        {
            if (Type == 1)
            {
                std::string* Brands = nullptr;
                int BrandsSize = 0;
                for (int i = 0; i < Size; i++)
                {
                    if (BrandsSize == 0)
                    {
                        BrandsSize++;
                        Brands = new std::string[BrandsSize];
                        Brands[0] = Phones[i].Brand;
                    }
                    else
                    {
                        bool IsNew = true;
                        for (int j = 0; j < BrandsSize; j++)
                        {
                            if(Brands[j]==Phones[i].Brand)
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
                for (int i = 0; i < BrandsSize; i++)
                {
                    std::cout<<std::endl<<Brands[i]<<": \n";
                    for (int j = 0; j < Size; j++)
                    {
                        if(Brands[i]==Phones[j].Brand)
                            std::cout << "Id: " << j << ", Brand Name: " << Phones[j].Brand << ", Model name:" << Phones[j].Model << ", Form factor: " << Phones[j].FormFactor << ", Year of issue: " << Phones[j].YearOfIssue << ", Screen Size: " << Phones[j].ScreenSize << ", Price: " << Phones[j].Price << std::endl;
                    }
                }
            }
            else if (Type == 2)
            {
                std::string FormFactor;
                double ScreenSize;
                std::cout<<"Pass Form factor (x:y): ";
                std::cin>>FormFactor;
                std::cout << "Pass Screen size (in inches): ";
                std::cin>>ScreenSize;
                if (std::cin.fail())
                {
                    std::cout << "Please enter a valid data" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(80, '\n');
                }
                else{
                    for (int i = 0; i < Size; i++)
                    {
                        if (FormFactor == Phones[i].FormFactor && ScreenSize == Phones[i].ScreenSize)
                            std::cout << "Id: " << i << ", Brand Name: " << Phones[i].Brand << ", Model name:" << Phones[i].Model << ", Form factor: " << Phones[i].FormFactor << ", Year of issue: " << Phones[i].YearOfIssue << ", Screen Size: " << Phones[i].ScreenSize << ", Price: " << Phones[i].Price << std::endl;
                    }
                }

            }
            else if (Type == 3)
            {
                std::string* Brands = nullptr;
                int BrandsSize = 0, *BrandsCount = nullptr, Max = 0, MaxIndex;

                for (int i = 0; i < Size; i++)
                {
                    if (BrandsSize == 0)
                    {
                        BrandsSize++;
                        Brands = new std::string[BrandsSize];
                        BrandsCount = new int[BrandsSize];
                        Brands[0] = Phones[i].Brand;
                        BrandsCount[0] = 1;
                    }
                    else {
                        bool IsNew = true;
                        for (int j = 0; j < BrandsSize; j++)
                        {
                            if (Phones[i].Brand == Brands[j])
                            {
                                IsNew = false;
                                BrandsCount[j]++;
                                break;
                            }
                        }
                        if (IsNew)
                        {
                            BrandsSize++;
                            std::string *Tmp = new std::string[BrandsSize];
                            int *Tmp1 = new int[BrandsSize];
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

                for (int i = 0; i < BrandsSize; i++)
                {
                    if (BrandsCount[i] > Max)
                    {
                        Max = BrandsCount[i];
                        MaxIndex = i;
                    }
                }
                if(Brands!= nullptr)
                    std::cout<< "Most quantity has: "<<Brands[MaxIndex]<<", with amount of: "<<Max<<std::endl;
            }
            else if (Type == 4)
            {
                double* ScreenSizes = nullptr;
                int ScreenSizesSize = 0, * ScreenSizesCount = nullptr, Max[3] = {0,0,0}, MaxIndex[3]={0,0,0};

                for (int i = 0; i < Size; i++)
                {
                    if (ScreenSizesSize == 0)
                    {
                        ScreenSizesSize++;
                        ScreenSizes = new double[ScreenSizesSize];
                        ScreenSizesCount = new int[ScreenSizesSize];
                        ScreenSizes[0] = Phones[i].ScreenSize;
                        ScreenSizesCount[0] = 1;
                    }
                    else {
                        bool IsNew = true;
                        for (int j = 0; j < ScreenSizesSize; j++)
                        {
                            if (Phones[i].ScreenSize == ScreenSizes[j])
                            {
                                IsNew = false;
                                ScreenSizesCount[j]++;
                                break;
                            }
                        }
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

                for (int i = 0; i < ScreenSizesSize; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (ScreenSizesCount[i] > Max[j])
                        {
                            if (j == 0) 
                            {
                                Max[2] = Max[1];
                                Max[1] = Max[0];
                                MaxIndex[2] = MaxIndex[1];
                                MaxIndex[1] = MaxIndex[0];
                            }
                            else if (j == 1)
                            {
                                Max[2] = Max[1];
                                MaxIndex[2] = MaxIndex[1];
                            }
                            Max[j] = ScreenSizesCount[i];
                            MaxIndex[j] = i;
                            break;

                        }
                    }
                    
                }
                if (ScreenSizes != nullptr)
                    std::cout << "Top 3 is: " << ScreenSizes[MaxIndex[0]]<<", " << ScreenSizes[MaxIndex[1]] << ", " << ScreenSizes[MaxIndex[2]] << std::endl;
            }
            else if (Type == 5)
            {
                std::cout<<"Full phones list:\n";
                for (int i = 0; i < Size; i++)
                {
                    std::cout<<"Id: "<<i<<", Brand Name: "<<Phones[i].Brand<<", Model name:"<< Phones[i].Model<<", Form factor: "<<Phones[i].FormFactor<<", Year of issue: "<< Phones[i].YearOfIssue<<", Screen Size: "<< Phones[i].ScreenSize<<", Price: "<< Phones[i].Price<<std::endl;
                }
            }
            system("pause");
        }
};

void menu(int Id);

int main()
{
    int Working = 1,Program = 0;
    StoredPhones Warehouse1;
    while (Working)
    {
        menu(0);
        std::cin>>Program;
        if (Program == 0)
        {
            std::cout << "Turning off the program...";
            Working = 0;
        }
        else if (Program == 1)
        {
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
            if (std::cin.fail())
            {
                std::cout << "Please enter a valid data" << std::endl;
                std::cin.clear();
                std::cin.ignore(80, '\n');
            }
            else
                Warehouse1.Add(Tmp);
        }
        else if (Program == 2)
        {
            int Tmp;
            std::cout << "Pass the Phone Id you want to delete: ";
            std::cin >> Tmp;
            if (std::cin.fail())
            {
                std::cout << "Please enter a valid integer" << std::endl;
                std::cin.clear();
                std::cin.ignore(80, '\n');
            }
            else
                Warehouse1.Delete(Tmp);
        }
        else if (Program == 3)
        {
            int Tmp;
            menu(1);
            std::cin>>Tmp;
            if (std::cin.fail())
            {
                std::cout << "Please enter a valid integer" << std::endl;
                std::cin.clear();
                std::cin.ignore(80, '\n');
            }
            else
            {
                if (Tmp > 0 && Tmp < 6)
                    Warehouse1.Report(Tmp);
                else if (Tmp == 0)
                    continue;
                else
                {
                    std::cout << "an error occured, turning off the program...";
                    Working = 0;
                }
            }
        }
        else
        {
            std::cout<<"an error occured, turning off the program...";
            Working = 0;
        }

    }
    return 0;
}

void menu(int Id)
{
    system("cls");
    if(Id == 0)
    {
        std::cout << "Welcome to the cell phone shop warehouse\n";
        std::cout << "Please insert wanted option:\n";
        std::cout << "[1]-for adding phone to warehouse\n";
        std::cout << "[2]-for adding phone to warehouse\n";
        std::cout << "[3]-for adding phone to warehouse\n";
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
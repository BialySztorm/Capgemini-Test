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
                
            }
            else if (Type == 2)
            {

            }
            else if (Type == 3)
            {

            }
            else if (Type == 4)
            {

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
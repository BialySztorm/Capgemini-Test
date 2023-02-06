#pragma once

void menu(int Id);

struct Phone {
    std::string Brand;
    std::string Model;
    std::string FormFactor;
    int YearOfIssue;
    double ScreenSize;
    double Price;
};

class StoredPhones {
    Phone* Phones = nullptr;
    int Size = 0;
public:
    void Add(Phone NewPhone);
    void Delete(int Id);
    void Report(int Type);
};
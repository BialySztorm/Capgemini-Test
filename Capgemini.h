#pragma once

void menu(int Id);
std::vector<std::string> split_string(const std::string& str, const std::string& delimiter);

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
    std::string Location;
public:
    StoredPhones();
    ~StoredPhones();
    void Add(Phone NewPhone);
    void Delete(int Id);
    void Report(int Type);
};
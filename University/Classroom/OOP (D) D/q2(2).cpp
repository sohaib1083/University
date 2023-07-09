#include <iostream>
using namespace std;

class emp
{
protected:
    string name, ID, date, education, certifications, lang;

public:
    emp(string n, string id, string d, string e, string c, string l)
    {
        name = n;
        ID = id;
        date = d;
        education = e;
        certifications = c;
        lang = l;
    }
};

class doctor : public emp
{
    string speciality;

public:
    doctor(string n, string id, string d, string e, string c, string l, string sp) : emp(n, id, d, e, c, l)
    {
        speciality = sp;
    }
};

class nurse : public emp
{
    string training;

public:
    nurse(string n, string id, string d, string e, string c, string l, string t) : emp(n, id, d, e, c, l)
    {
        training = t;
    }
};

class FrontDesk : public emp
{
public:
    FrontDesk(string n, string id, string d, string e, string c, string l) : emp(n, id, d, e, c, l)
    {
    }
};

class Technician : public emp
{
public:
    Technician(string n, string id, string d, string e, string c, string l) : emp(n, id, d, e, c, l)
    {
    }
};

class Technologist : public emp
{
public:
    Technologist(string n, string id, string d, string e, string c, string l) : emp(n, id, d, e, c, l)
    {
    }
};

int main(void)
{
    doctor d1("Sohaib", "21k-3278", " 19-02-2002", "BSC-Med", "Alevel", "English", "heart");
    nurse d2("Sassi", "21k-3378", " 19-01-2002", "BSC-Med", "FSC", "English", "Management");
    FrontDesk d3("Bruhh", "21k-3278", " 19-02-2002", "BSC-Med", "Alevel", "English");
    Technician d4("XD", "21k-3278", " 19-02-2002", "BSC-Med", "Alevel", "English");
    Technologist d5("Sameer", "21k-3278", " 19-02-2002", "BSC-Med", "Alevel", "English");
    cout << "Data stored..";

    return 0;
}

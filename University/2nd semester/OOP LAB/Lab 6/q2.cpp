#include <iostream>
#include <string>

class employee
{
    std ::string name;
    int num;

protected:
    void set_name(std ::string name)
    {
        this->name = name;
    }
    void set_num(int num)
    {
        this->num = num;
    }
    std :: string get_name(void)
    {
        return name;
    }
    int get_num(void)
    {
        return num;
    }
};

class manager : protected employee
{
    std ::string title;
    int golfDues;
    public:
    manager(std :: string name, int num, std :: string title, int golfDues)
    {
        set_name(name);
        set_num(num);
        this->title = title;
        this->golfDues = golfDues;
    }
    void show_manager(void)
    {
        std :: cout << "\nEmployee name: " << get_name()
             << "\nNumber: " << get_num()
             << "\nTitle: " << title
             << "\ngolf dues: " << golfDues;
    }
};

class scientist : protected employee
{
    std ::string title;
    int num_publication;
    public:
    scientist(std :: string name, int num, std :: string title, int num_publication)
    {
        set_name(name);
        set_num(num);
        this->title = title;
        this->num_publication = num_publication;
    }
    void show_scientist(void)
    {
        std :: cout << "\nEmployee name: " << get_name()
             << "\nNumber: " << get_num()
             << "\nTitle: " << title
             << "\nNumber of publications: " << num_publication;    
    }
};

class Laborer : protected employee
{
    std ::string title;
    public:
    Laborer(std :: string name, int num, std :: string title)
    {
        set_name(name);
        set_num(num);
        this->title = title;
    }
    void show_Laborer(void)
    {
        std :: cout << "\nEmployee name: " << get_name()
             << "\nNumber: " << get_num()
             << "\nTitle: " << title;
    }
};



int main(void)
{
    manager person1("Haris Kabir", 34512, "Executive", 12);
    person1.show_manager();

    std :: cout<< std :: endl;

    scientist person2("Sohaib Shamsi", 23490, "Top-tier", 13);
    person2.show_scientist();

    std :: cout<< std :: endl;

    Laborer person3("Aayan Sarosh", 12908, "Surveyor");
    person3.show_Laborer();
}


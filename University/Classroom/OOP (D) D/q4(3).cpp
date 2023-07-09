#include <iostream>
#include <string>
using namespace std;

class student
{
    string name;
    string r_num;
    int s;
    char sec;

public:
    student(string name, string r_num, int s, char sec)
    {
        this->name = name;
        this->r_num = r_num;
        this->s = s;
        this->sec = sec;
    }

    void set_name(string n)
    {
        name = n;
    }

    string get_name()
    {
        return name;
    }

    void set_r_num(string r)
    {
        r_num = r;
    }

    string get_r_num()
    {
        return r_num;
    }

    void set_s(int s)
    {
        s = s;
    }

    int get_s()
    {
        return s;
    }

    void set_sec(char s)
    {
        sec = s;
    }

    char get_sec()
    {
        return sec;
    }
};

int main()
{
    string name = "Sohaib Sarosh Shamsi";
    string r_num = "21K-3278";
    int s = 2;
    char sec = 'D';

    student obj(name, r_num, s, sec);

    cout << "Student Name: " << obj.get_name() << endl;
    cout << "Roll No: " << obj.get_r_num() << endl;
    cout << "semester: " << obj.get_s() << endl;
    cout << "sec: " << obj.get_sec() << endl;
}

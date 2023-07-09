#include <iostream>
#include <string>

using namespace std;

class record{
    string name;
    int student_id;
    double cgpa;
    float w_count;

    public:
    void setter (string n)
    {
        name = n;
    }
    void setter (int n)
    {
        student_id = n;
    }
    void setter (double n)
    {
        cgpa = n;
    }
    void setter (float n)
    {
        w_count = n;
    }

    string get_name (void)
    {
        return name;
    }
    int get_id (void)
    {
        return student_id;
    }
    double get_cgpa (void)
    {
        return cgpa;
    }
    int get_count (void)
    {
        return int(w_count);
    }
};

int main (void)
{
    record students[5];
    string name;
    int student_id;
    float w_count;
    double cgpa;

// storing information using setter functions
    for (int i = 0; i < 5; i++)
    {
        cout<< "Enter name for student "<< i+1<< endl;
        fflush(stdin);
        getline(cin, name);
        fflush(stdin);
        students[i].setter(name);

        cout<< "Enter student id for student "<< i+1<< endl;
        cin>> student_id;
        students[i].setter(student_id);

        cout<< "Enter warning count for student "<< i+1<< endl;
        cin>> w_count;
        students[i].setter(w_count);

        cout<< "Enter cgpa for student "<< i+1<< endl;
        cin>> cgpa;
        students[i].setter(cgpa);
    }

    cout<< endl<<endl;

// retreiving information using getter function

    for (int i = 0; i < 5; i++)
    {
        cout<< "Name for student "<< i+1<<" = "<< students[i].get_name()<< endl;
 
        cout<< "Student id for student "<< i+1<<" = "<< students[i].get_id()<< endl;

        cout<< "Warning count for student "<< i+1<< " = "<< students[i].get_count()<< endl;

        cout<< "cgpa for student "<< i+1<<" = "<< students[i].get_cgpa()<< endl;

        cout<< endl;
    }



}
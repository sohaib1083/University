#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Assess
{
    string name;
    char *roll_num;
    float quizmarks, midterm, finalmarks;
    static int count;

public:
    Assess(string name, char r[20], float quizmarks = 0, float midterm = 0, float finalmarks = 0)
    {
        roll_num = r;
        roll_num = r;
        this->name = name;
        this->quizmarks = quizmarks;
        this->midterm = midterm;
        this->finalmarks = finalmarks;
        count++;
    }

    Assess(Assess &s)
    {
        roll_num = s.roll_num;
        name = s.name;
        quizmarks = s.quizmarks;
        midterm = s.midterm;
        finalmarks = s.finalmarks;
    }

    ~Assess()
    {
        delete[] roll_num;
        count--;
    }

    void display(void)
    {
        cout << "Details: " << endl;
        cout << name << endl
             << roll_num << endl
             << "quiz marks:" << quizmarks << endl
             << "mid term marks:" << midterm << endl
             << "final marks: " << finalmarks << endl;
        generateGrade();
        cout << endl;
        AvgScore();
    }
    void AvgScore()
    {
        cout << "The average score is: " << (quizmarks + midterm + finalmarks) / 3;
    }
    void generateGrade()
    {

        float perc = (quizmarks * 0.25) + (midterm * 0.25) + (finalmarks * 0.50);
        cout << "The grade is: ";
        if (perc >= 90 && perc <= 100)
        {
            cout << "A";
        }
        else if (perc >= 80 && perc < 90)
        {
            cout << "B";
        }
        else if (perc >= 70 && perc < 80)
        {
            cout << "C";
        }
        else if (perc >= 60 && perc < 70)
        {
            cout << "D";
        }
        else if (perc < 60)
        {
            cout << "D";
        }
    }
};

int Assess ::count = 0;

int main(void)
{
    Assess s1("sohaib", "21k-3278", 50, 50, 50);
    s1.display();

    cout << "2nd user: ";
    Assess s2("sohaib", "21k-3278", 50); // missed exam
    s2.display();

    // copy constructor

    Assess stud1("sohaib", "21k-3278", 70, 60, 30);

    Assess stud2(stud1);

    Assess stud3 = stud1;

    stud2.display();
    stud3.display();

    return 0;
}

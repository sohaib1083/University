#include <iostream>
#include<string>
#include <iomanip>

using namespace std;

int main (void)
{

    string name;

    cout<< "Enter student name: "<< endl;
    getline(cin, name);

    float marks[5];
    float sum;

    // storing marks for five subject in array
    for (int i = 0; i < 5; i++)
    {
        cout<< "Enter marks for subject "<< i+1<< ":"<< endl;
        cin>> marks[i];
        sum = sum + marks[i];   
    }

    // calculating average
    float average = sum / 5;

    // output
    cout<< "Student name: "<< name<< endl;
    cout<< "Test score: ";
    for(int j = 0; j < 5; j++)
    {
        cout<<marks[j]<<" ";
    }
    cout<<endl;
    cout<< "Average test score: "<< fixed << setprecision(2)<< average;

    return 0;
}
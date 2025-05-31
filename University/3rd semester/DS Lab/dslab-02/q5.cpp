#include <iostream>
using namespace std;

int main (void)
{
    int rows_num;

    cout<< "Enter number of rows: ";
    cin>> rows_num;

    // store names
    string name_array[rows_num];
    // store number of subjects
    int subjects_num[rows_num];

    for (int i=0; i<rows_num; i++)
    {
        cout<<"Enter name for student #"<<i+1<<" :";
        cin>>name_array[i];
    }

    // pointer array
    double **ptr = new double*[rows_num];

    int columns_num;
    for (int i=0; i<rows_num; i++)
    {
        cout<< "Enter number of subjects of student "<<name_array[i]<< " :";
        cin>> columns_num;

        ptr[i]= new double[columns_num];
        subjects_num[i]=columns_num;

        cout<< "\nEnter marks of student "<<name_array[i]<< " : ";
        for (int j=0; j<columns_num; j++)
        {
            cin>> *(*(ptr+i)+j);
        }
    }

    for (int i=0; i<rows_num; i++)
    {
        double sgpa=0.0;
        for (int j=0; j<subjects_num[i]; j++)
        {
            sgpa+=*(*(ptr+i)+j);
        }
        sgpa = (sgpa)/(subjects_num[i]);
        cout<< "\nThe sgpa for "<<name_array[i]<<" is: "<< sgpa<< ".";
    }





    return 0;
}
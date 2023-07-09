#include<iostream>
#include<fstream>
using namespace std;

int main (int argc, char *argv[])
{

    ofstream file1;
    file1.open(argv[1]);
    
    file1<< argv[2];
    file1.close();

    file1.open(argv[3]);

    ifstream file2;
    file2.open(argv[1]);

    char ch;
    ch=file2.get();

    while(!file2.eof())
    {
        file1<< ch;
        ch=file2.get();
    }
    file1.close();
    file2.close();

    return 0;
}
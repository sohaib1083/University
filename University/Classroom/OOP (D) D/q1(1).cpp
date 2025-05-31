#include<string>
#include<iostream>
#include <fstream>
using namespace std;

int main (void)
{
    string str;
    cout<< "Enter string:";
    cin>> str;

    int l = str.length();

    fstream file;
    file.open("my_string.txt", ios :: out);
    
	if (file.is_open())
    {
        file << str;
    }
    else
	{
        cout<< "Error";
    }
	file.close();

    
	char s;

    file.open("my_string.txt", ios :: in);
    while (file.is_open())
    {
        cout<< "The output from file is: ";
        char c;

        while(!file.eof())
        {
            file.get(c);
            cout<< c;
        }
        file.close();
    }
    
    return 0;
}

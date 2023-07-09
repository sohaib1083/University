#include <iostream>
#include <fstream>
using namespace std;



int main (void)
{
	ofstream file1;
	string f1_content;
	
	file1.open("copy1.txt", ios :: out);
	cout<< "Enter content for file 1: ";
	cin>> f1_content;
	file1<< f1_content;
	file1.close();
	
	
	ofstream file2;
	file2.open("copy2.txt", ios:: out);
	
	ifstream file3;
	file3.open("copy1.txt", ios :: in);
	
	string line;
	if (file3.is_open())
	{
	while (!file3.eof())
	{
		getline (file3, line);
		file2 << line;
	}
	file3.close();
    }
    
    file2.close();
	
	 
	return 0;
}

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class person{
	int age;
	char name[50];
	public:
	person(int a, char n[50])
	{
	age = a;
	strcpy(name, n);
	//cout<<name << n;
	//name = n;	
	}
	
	void fetch_data()
	{
	cout<< age << endl<< name;	
	}	
};

int main (void)
{
	person person1(10, "Sohaib");
	
	ofstream file;
	
	file.open("person.bin", ios :: app|ios :: binary);
	if (!file.is_open())
	{
		cout<< "creation of new file failed! ";
		exit(0);
	}
	
	file.write((char *)&person1, sizeof(person1));
	
	ifstream file1;
	
	file1.open("person.bin", ios :: out|ios :: binary);
	while (file1.read((char *)&person1, sizeof(person1)) != NULL)
	{
		person1.fetch_data();
		file1.close();	
	}
		
	return 0;
}


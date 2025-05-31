#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main (void)
{
	ofstream file1;
	file1.open("story.txt", ios :: out);
	file1 << "the shape of the whale";
	file1.close();
	
	ifstream file;
	int count=0;
	char c[20], ch[20];
	
	file.open("story.txt", ios :: in);
	
	if (file.is_open())
	{
	while (file)
	{
		file >> ch;
		if (strcmp(ch, "the") == 0)
		{
			count++;
		}
	
	}
	file.close();	
	} 
	
	cout<< "number of times 'the' was encountered: "<< count;
	return 0;
}

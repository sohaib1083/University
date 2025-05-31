#include <iostream>
#include <fstream>
using namespace std;

int main (void)
{
	ifstream file;
	file.open("STORY.txt", ios :: in);
	int count_A = 0, count_line = 0;
	string line;
	if (file.is_open())
	{
		while (!file.eof())
		{
		count_line++;	
		getline (file, line);
		if ('A' == line[0])
		{
			count_A++;
		}
	    }
	    file.close();
	}
	
	
	cout<< "Number of lines not starting with A: "<< count_line-count_A;
	return 0;
}

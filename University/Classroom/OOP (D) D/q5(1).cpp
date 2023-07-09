#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class participant{
	string ID, name;
	double score;
	public:
	static int max;	
	
	void input()
	{
		max++;
		cout<< "enter ID: ";
		cin>> ID;
		cout<<"\nEnter name: ";
		cin>> name;
		cout<<"\nEnter score: ";
		cin>> score;
		
		ofstream file;
		file.open("participant.dat", ios :: app);
		file<< ID << name << score << endl;
		file.close();
	}
	
	void output ()
	{
		string search_id;
		cout<< "Enter ID to search: ";
		cin>> search_id;
		
		ifstream file1;
		file1.open("participant.dat", ios :: in);
		
		string line;
		
		if (file1.is_open())
		{
		while (!file1.eof())
		{
            //cout<< ID<< name<< score;
            getline (file1, line);
			if (search_id == line.substr(0,1))
            {           	
            cout<< line<< endl;
			}
		}
		file1.close();
	    }
	}
};

int participant :: max = 0;

int main (void)
{
	participant obj1;
	obj1.input();
	
	obj1.output();
	cout<< obj1.max;
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

struct baseball_player{
    string name;
    float home_run;
    int number_of_hits;
}players[10];

// proto-type
void AddData (int);
void showData (int);
void modify (int);

int main (void)
{
    int choice, p = 0;

    do{
    cout<< "Enter your choice "<< endl;
    cout<< "press 1 for showing data stored"<< endl;
    cout<< "press 2 for initialising data in structure"<< endl;
    cout<< "press 3 for updating data for a player "<< endl;
    cout<< "press 4 to exit "<< endl;

    cin >> choice;

    switch (choice)
    {
        case 1:
        showData(p);
        break;

        case 2:
        // initialise data in struct: max = 10
        cout<< "For how many players you want to add data for: "<< endl;
        cin>> p;
        AddData(p);
        break;

        case 3:
        modify(p);
        break;

        case 4:
        break;

        default:
        cout<< "Wrong choice, try again.. "<< endl;
        getchar();
        main();

    }
    } while (choice != 4);

    cout<< "exiting the program.....";
    getchar();

    return 0;
}

void showData (int p)
{
    if (p == 0)
    {
        cout<< "There's no data to show."<< endl;
    }
    else{

    for (int i = 0; i < p; i++)
    {
        cout<< "Player number : " << i+1<< " ==> "<< endl;
        cout<< "Enter name of player : "<< players[i].name<< endl;
        cout<< "Enter home runs of player : "<< players[i].home_run<< endl;
        cout<< "Enter number of hits of player : "<< players[i].number_of_hits<< endl<< endl;
    }

    }

}

void AddData (int p)
{

    for (int i = 0; i < p; i++)
    {
        cout<< "Enter name of player "<< i + 1 << endl;
        fflush(stdin);
        getline(cin, players[i].name);

        cout<< "Enter home runs of player "<< i + 1 << endl;
        cin>> players[i].home_run;

        cout<< "Enter number of hits of player "<< i + 1 << endl;
        cin>> players[i].number_of_hits;
    }

}

void modify (int p)
{
    string search_name;

    cout << "Enter name of player:"<< endl;
    fflush(stdin);
    getline(cin, search_name);
    fflush(stdin);

    int i, flag=0;

    for (i = 0; i < p; i++)
    {

        if (search_name == players[i].name){
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        cout<< "Name not found.."<< endl;
    }
    else if (flag == 1){

    // updating record with user's input
    cout<< "Enter new name for player:"<< endl;
    fflush(stdin);
    getline(cin, players[i].name);
    
    cout<< "Enter new home run for player:"<< endl;
    cin>> players[i].home_run;
    cout<< "Enter new number of hits for player:"<< endl;
    cin>> players[i].number_of_hits;

    cout<< endl<< "record updated.."<< endl;

    }

}
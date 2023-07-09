#include <iostream>

using namespace std;

class Node
{
    public:
        Node *next;
        int data;

        Node(int d)
        {
            data = d;
            next = NULL;
        }
};

class Moves
{
    public:
        Node *Head;

        void insert(int count)
        {
            Node *temp = Head, *newnode = new Node(count);

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }



};
// bool is_check(int arr[][3], int row, int col, char c)
// {
//     if(arr[row][col] == c)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool check_victory(int arr[][3], int size, int row, int col)
// {
//     if(row >= 3 || col >= 3)
//     {
//         return false;
//     }
//     else
//     {
//         if(is_check(arr, size, row, col+1))
//         [
//             check_victory(arr, size, row, col+1);
//         ]
//     }
// }

void print(char arr[][3], int size)
{
    for (int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            cout<<arr[i][j]<< "     ";
        }
        cout<< endl;
    }
}

void check_empty(int arr[][3], int size)
{
    cout << "The empty slots are: " << endl;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(arr[i][j] == 'A')
            {
                cout << "sad";
            }
        }
    }
}

void input(char arr[][3], int size, int player)
{
    int row, col;

    cout << "Enter your row & column: ";
    cin >> row >> col;

    if(player == 1)
    {
        arr[row][col] = 'X';
    }
    else
    {
        arr[row][col] = 'Y';
    }    
}

void Game(int arr[][3])
{
    while(1)
    {

    }
}

int main()
{
    char arr[3][3]; Node *head = NULL;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            arr[i][j] = 'A';
        }
    }

    arr[2][1] = 'X';

    print(arr, 3);



    return 0;   
}
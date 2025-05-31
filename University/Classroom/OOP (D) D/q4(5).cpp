#include <iostream>
#include <string>

using namespace std;

class book{
    string book_name;
    int isbn;
    string author_name;
    string publisher;
    public:
void setb(string a){
    book_name = a;
}
void seti(int b){
    isbn = b;
}
void seta(string c){
    author_name = c;
}
void setp(string d){
    publisher = d;
}
string getname(void){
    return book_name;
}

};

int main (void)
{
    book BookTest[5];
    string b, a, p;
    int isbn;

    for (int i = 0; i < 5; i++)
    {
        cout<< "\nEnter book name: ";
        getline (cin, b);
        BookTest[i].setb(b);

        cout<< "\nEnter isbn: ";
        cin >> isbn;
        BookTest[i].seti(isbn);

        cout<< "\nEnter author name: ";
        getline (cin, a);
        BookTest[i].setb(a);

        cout<< "\nEnter book name: ";
        getline (cin, p);
        BookTest[i].setb(p);

    }
    string search;

    cout<< "\nEnter book name to search:";
    cin>> search;

    int index, flag;

    for (int i = 0; i < 5; i++)
    {
        string m = BookTest[i].getname();
        if (search == m)
           index = i;
           flag = 1;
           
    }

    if (flag == 1)
    {
        cout<< BookTest[index].getname();
    }
    else{
        cout<< "Not found";

    }

}
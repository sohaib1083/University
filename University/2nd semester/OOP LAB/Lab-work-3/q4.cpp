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

string getBookInfo(){
    string s = book_name + " " + to_string(isbn) + " " + author_name + " " + publisher;
    return s;
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
        fflush(stdin);
        getline (cin, b);
        BookTest[i].setb(b);
        fflush(stdin);

        cout<< "\nEnter isbn: ";
        cin >> isbn;
        BookTest[i].seti(isbn);

        cout<< "\nEnter author name: ";
        fflush(stdin);
        getline (cin, a);
        BookTest[i].seta(a);
        fflush(stdin);

        cout<< "\nEnter publisher name: ";
        fflush(stdin);
        getline (cin, p);
        BookTest[i].setp(p);
        fflush(stdin);

        cout<<"\n\n";

    }

    cout<<"\n\n\n************* get book info for a specific book ***************";

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

    cout<<"\n\n\n************* printing string returned by function ***************"<< endl;

    if (flag == 1)
    {

        cout<< BookTest[index].getBookInfo();
    }
    else{
        cout<< "Not found";

    }

}
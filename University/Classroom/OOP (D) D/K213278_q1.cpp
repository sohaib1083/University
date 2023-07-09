#include <iostream>
using namespace std;

class ISBN
{
    string fp, sp, tp, fourth_part;
    string isbn_num;

public:
    ISBN(string fp, string sp, string tp, string fourth_part)
    {
        this->fp = fp;
        this->sp = sp;
        this->tp = tp;
        this->fourth_part = fp;
        isbn_num = fp + " " + sp + " " + tp + " " + fourth_part;
    }
    ISBN()
    {
    }
    string get_isbn()
    {
        return isbn_num;
    }
    void set_isbn(string i)
    {
        isbn_num = i;
    }
};

class book : public ISBN
{
    string book_title, author, publisher, city, date_publication;
    double price;
    ISBN isbnNum;

public:
    book(string b, string a, string p, string c, string d, double pr, string fp, string sp, string tp, string fourth_part) : ISBN(fp, sp, tp, fourth_part)
    {
        book_title = b;
        author = a;
        publisher = p;
        city = c;
        date_publication = d;
        price = pr;
    }

    void setBookISBN(string fp, string sp, string tp, string fourth_part)
    {
        string i = fp + " " + sp + " " + tp + " " + fourth_part;
        set_isbn(i);
    }

    string get_author()
    {
        return author;
    }

    string getBookISBN()
    {
        string i = get_isbn();
        return i;
    }

    void print_details()
    {
        cout << "\nBook Title: " << book_title;
        cout << "\nBook author: " << author;
        cout << "\nPubisher: " << publisher;
        cout << "\nISBN: " << get_isbn();
    }
};

int main(void)
{
    book obj1("Last summer", "David Wiese", "Daffodils publication", "New jersy", "20/10/2009", 2.70, "1", "941831", "39", "6");
    obj1.setBookISBN("0", "941831", "39", "6");
    cout << endl
         << obj1.get_author();
    cout << endl
         << obj1.get_isbn() << endl;

    obj1.print_details();

    return 0;
}
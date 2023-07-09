#include <iostream>
using namespace std;

class fruit
{
protected:
    static int num;
    void add_fruit(int n)
    {
        num = num + n;
    }

public:
    static int get_num()
    {
        return num;
    }
};

int fruit ::num;

class apple : public fruit
{
    int num;

public:
    apple(int num)
    {
        this->num = num;
        fruit ::num += apple ::num;
    }
    int get_apple(void)
    {
        return num;
    }
};

class mangoes : public fruit
{
    int num;

public:
    mangoes(int num)
    {
        this->num = num;
        fruit ::num += mangoes ::num;
    }
    int get_mangoes(void)
    {
        return num;
    }
};

int main(void)
{
    apple p1(2);
    mangoes m1(3);
    cout << "Quantities are as followed: " << endl
         << "Apple: " << p1.get_apple() << endl
         << "Mangoes: " << m1.get_mangoes() << endl
         << "The total count for fruits is: " << m1.get_num();
    return 0;
}
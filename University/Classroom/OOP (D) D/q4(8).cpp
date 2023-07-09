#include <iostream>
#include<string>
#include <iomanip>

using namespace std;

// structure to store menu items
struct menuItemType{

    string menuItem;
    double menuPrice;

}menuList[8] = {"Plain Egg", 1.45, "Bacon and Egg", 2.45, "Muffin", 0.99, "French Toast", 1.99, "Fruit basket", 2.49, "Cereal", 0.69, "Coffee", 0.50, "Tea", 0.75};

// proto-type
double search (string item);

int main (void)
{
    // displaying menu
    cout<<"Welcome to Johnny's restaurant"<< endl;
    cout<<"Below is the available menu:-"<< endl;
    for (int i = 0; i < 8; i++)
    {
        cout<< menuList[i].menuItem << "   $"<<fixed << setprecision(2)<< menuList[i].menuPrice<< endl;
    }
    
    cout<< endl<< endl;

    char choice;
    string search_item;
    double price, gross_bill, tax, amount_due;
    int counter=0;
    menuItemType my_order[100];

    // storing order in the new struct : my_order
    do 
    {
    fflush(stdin);	
    cout<< "Enter name of the item you want:"<< endl;
    getline (cin, search_item);
    price = search(search_item);
    fflush(stdin);

    my_order[counter].menuItem = search_item;
    my_order[counter].menuPrice = price;

    gross_bill += price;
    counter++;    

    cout<< "Do you want to conntinue? (Y/N)"<<endl;
    cin >> choice;    
    } while (choice == 'Y' ); 

    // calculating tax and final bill
    tax = gross_bill * 0.05;
    amount_due = gross_bill-tax;

    cout<< endl<<endl;

    // displaying bill for user
    cout<<"Welcome to Johnny's restaurant"<< endl;
    for (int i = 0; i < counter; i++)
    {
        cout<< my_order[i].menuItem<< "  " <<fixed << setprecision(2)<< my_order[i].menuPrice<< endl;
    }
    cout<< "Tax: "<< fixed<< setprecision(2) << tax<< endl;
    cout<< "Amount due: "<< fixed<< setprecision(2)<< amount_due<< endl; 

    return 0;
}

// function to search food and return price
double search (string item)
{
    int flag = 0;
    int i;

    for (i=0; i < 8 ; i++)
    {
        if (item == menuList[i].menuItem)
        {
            flag = 1;
            break;
        }
    }

if (flag == 1)
{
    return menuList[i].menuPrice;
}
 else if (flag == 0)
 {
 	cout<< endl<< endl;
     cout<<"Error!!!, Not included in the menu, please order again from the beginnning..."<< endl;
     main();
 }
}

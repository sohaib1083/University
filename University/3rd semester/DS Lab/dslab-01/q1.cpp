#include <iostream>

int main(int argc, char *argv[])
{
    std :: cout << "You have entered " << argc
         << " arguments:" << "\n";
         
    for (int i = 0; i < argc; ++i)
        std :: cout << argv[i] << "\n";

    std:: cout<< "The total of "<< argc<< " arguments provided by the user.";   
        
    return 0;
}

#include <iostream>
using namespace std;

class animal{
    public:
    void animalSound()
    {
        cout<< "The animal makes a sound"<< endl;
    }
};

class cat : public animal{
    public:
    void animalSound()
    {
        cout<< "The cat says meow."<< endl;
    }
};

class dog : public animal{
    public:
    void animalSound()
    {
        cout<< "The dog says bow wow"<< endl;
    }
};

class duck : public animal{
    public: 
    void animalSound()
    {
        cout<< "The duck says quack quack"<< endl;
    }
};


int main (void)
{
    animal o1;
    o1.animalSound();
    
    cat o2;
    o2.animalSound();

    dog o3;
    o3.animalSound();

    duck o4;
    o4.animalSound();


    return 0;
}
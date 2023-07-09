#include <iostream>
#include <cmath>
using namespace std;

float volume (float side)
{
    return pow(side, 3);
}

float volume (float radius, float height)
{
    return (3.14*radius*radius*height);
}

float volume (float lenght, float breadth, float height)
{
    return (lenght*breadth*height);
}

int main (void)
{
    // cube 
    float vol1= volume (6);
    cout<< vol1<< endl;

    // cylinder
    float vol2 = volume(3, 4);
    cout<< vol2<< endl;

    // rectangular box
    float vol3 = volume(1, 2, 3);
    cout<< vol3<< endl;
}
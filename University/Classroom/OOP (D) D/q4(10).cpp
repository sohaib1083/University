#include <iostream>
#include <cmath>

using namespace std;

// proto-types
float distance (float x1, float y1, float x2, float y2);
float radius (float x1, float y1, float x2, float y2);
float circumference (float r);
float area (float r);

int main (void)
{

    float x1, x2, y1, y2;
    float r, c, a;

    cout<< "Enter co-ordinates for center of the circle (x,y) : "<< endl;
    cin>> x1 >> y1;

    cout<< "Enter co-ordinates for the point on the circle (x,y) : "<< endl;
    cin >> x2 >> y2;

    r = radius(x1, y1, x2, y2);
    c = circumference(r);
    a = area(r);

    cout<< endl<< endl;
    cout<< "radius : "<< r<< endl;
    cout<< "circumference : "<< c<< endl;
    cout<< "area : "<< a<< endl;

    return 0;
}

float radius (float x1, float y1, float x2, float y2)
{

    float r = distance(x1, y1, x2, y2);
    return r;

}

float distance (float x1, float y1, float x2, float y2)
{
    float sq_x = pow((x2 - x1), 2);
    float sq_y = pow((y2 - y1), 2);

    float dist = sqrt ((sq_x + sq_y));

    return dist;
}

float circumference (float r)
{
    const float PI = 3.1416;

    float c =  2 * PI * r;
    return c;
}

float area (float r)
{
    const float PI = 3.1416;

    float a = PI * pow(r, 2);
    return a;
}

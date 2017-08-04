#include <iostream>
#include <cmath> 
using namespace std;

#define PI 3.1415926
 
struct Rectangle{
    double center_x;
    double center_y;
    double width;
    double height;
    double angle; // counter-clockwise rotation angle
    Rectangle(double x, double y, double w, double h, double th): center_x(x), center_y(y), width(w), height(h), angle(th) {};
};

struct Point{
    double x;
    double y;
    Point(double x1, double y1): x(x1), y(y1) {};
};

bool isInsideRectangle(Rectangle &rec, Point &po)
{
    double angle_diff; // difference between rectangle rotation and two center's rotation
    if(po.x == rec.center_x) // tan is infinity
    {
        if(po.y < rec.center_y) angle_diff = -0.5 * PI - rec.angle;
        else angle_diff = 0.5 * PI - rec.angle;
    }
    else // normal tan
    {
        angle_diff = atan((po.y - rec.center_y) / (po.x - rec.center_x)) - rec.angle;
    }
    double dist = sqrt((po.y - rec.center_y)*(po.y - rec.center_y) + (po.x - rec.center_x)*(po.x - rec.center_x));
    double relative_x = abs(dist * cos(angle_diff));
    double relative_y = abs(dist * sin(angle_diff));
    return (relative_x < 0.5 * rec.width && relative_y < 0.5 * rec.height);
}

int main()
{
    
    Rectangle rect(10, 10, 5, 8, 0.25*PI);
    Point p1(1, 1); // outside rect 
    Point p2(9, 10); // inside rect
    cout << isInsideRectangle(rect, p1) << endl;
    cout << isInsideRectangle(rect, p2) << endl;
    return 0;
}

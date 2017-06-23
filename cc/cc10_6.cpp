// given a 2d graph with points on it, find a line that passes most number of points
// *** 0623: this class is not well written, change it later
#include <iostream>
#include <map>
#include <cmath> //abs
#include <cstdlib>
#include <ctime>
using namespace std;

struct point
{
    double x, y;
};

class Line
{
public:
    double epsilon, slope, intercept;
    bool bslope; // whether two points have slope
public:
    Line() {}
    Line(point p, point q)
    {
        epsilon = 0.0001;
        if(abs(p.x - q.x) > epsilon)
        {
            slope = (p.y - q.y) / (p.x - q.x);
            // because y = kx + b, so y-kx = b => intercept on y-axis
            intercept = p.y - slope * p.x;
            bslope = true; // have finite slope
        }
        else
        {
            bslope = false; //no finite slope
            intercept = p.x;  // use x as intercept because no (or all points are) intercept on y
        }
    }
    void print()
    {
        cout << "y = " << slope << "x + " << intercept << endl;
    }
};

// compare according to slope 
bool operator<(const Line &l1, const Line &l2)
{
    return l1.slope < l2.slope;
}

// equal in math approximate sense
bool equal(double a, double b)
{
    return abs(a - b) < 0.0001;
}

// whether two lines are equal
bool operator==(const Line &l1, const Line &l2)
{
    // slope and intercept is in approximately sense
    if(l1.bslope == l2.bslope && equal(l1.slope, l2.slope) && equal(l1.intercept, l2.intercept))
    {
        return true;
    }
    return false;
}

Line find_best_line(point *p, int point_num)
{
    Line bestline;
    bool first = true;
    map<Line, int> line_count;
    // simultaneouly compute line and get the maximal one
    for(int i = 0; i < point_num; ++i)
    {
        for(int j = i + 1; j < point_num; ++j)
        {
            Line l(p[i], p[j]);
            // *** is this a dull use of map??? ==>  check it
            // if cannot find this line
            if(line_count.find(l) == line_count.end())
            {
                line_count[l] = 1;
            }
            else
            {
                ++line_count[l];
            }
            // tempararily assign bestline to the firstline, later update it
            if(first) 
            {
                bestline = l;
                first = false;
            }
            else
            {
                if(line_count[l] > line_count[bestline])
                {
                    bestline = l;
                }
            }
        }
    }
    cout << line_count[bestline] << endl;
    return bestline;
}

int main()
{
    srand((unsigned)time(0));
    int graph_size = 10;
    int point_num = 500;
    point *p = new point[point_num];
    for(int i = 0; i < point_num; ++i)
    {
        // randomly get the x and y pos value
        p[i].x = rand() / double(RAND_MAX) * graph_size;
        p[i].y = rand() / double(RAND_MAX) * graph_size;
        cout << p[i].x << " " << p[i].y << endl;
    }
    Line l = find_best_line(p, point_num);
    l.print();
    delete [] p;
    return 0;
}


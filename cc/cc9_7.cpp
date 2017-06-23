//given height and weight of each person, compute the largest number of people in a tower (where the higher in the tower, both the shorter and lighter the person is)
// ==> implies that some people may not fit the tower
// aka. sorting with 2 measurement factors
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 100;
class Person
{
    int height;
    int weight;
public:
    Person(int h = 0, int w = 0): height(h), weight(w) { }
    void setVal(int h, int w)
    {
        height = h;
        weight = w;
    }
    friend bool cmp(const Person&, const Person&);
    friend int lis(Person p[], int n, int d[]);
};

bool cmp(const Person& p1, const Person& p2)
{
    if(p1.height == p2.height) return p1.weight < p2.weight; // 2nd priority
    else return p1.height < p2.height; // 1st priority
}

//count the largest num: lis(sorted person array, total num) => largest number
int lis(Person p[], int n, int d[])
{
    int k = 1; // at least 1 person can do
    d[0] = p[0].weight;
    for(int i = 1; i < n; ++i)
    {
        if(p[i].weight > d[k-1]) d[k++] = p[i].weight;
        else
        {
            int j;
            // going back until the weight is smaller than current person
            for(j = k - 1; j >= 0 && d[j] > p[i].weight; --j);
            d[j + 1] = p[i].weight;
            //k = j + 2;
        }
    }
    return k;
}


int main()
{
    freopen("cc9_7.in", "r", stdin);
    int num, h, w;
    cin >> num;
    int *d = new int[num];
    Person *ps = new Person[num];
    for(int i = 0; i < num; ++i)
    {
        cin >> h >> w;
        ps[i].setVal(h, w);
    }
    sort(ps, ps + num, cmp);
    cout << lis(ps, num, d) << endl;
    fclose(stdin);    
    // release
    delete [] d;
    delete [] ps;
    return 0;
}

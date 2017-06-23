#include <iostream>
#include <utility> // pair
#include <vector>
#include <algorithm>
using namespace std;

class Puzzle
{
private:
    int size; // puzzle height and width
    vector<pair<int, int> > limits;
    //int robot_posx; 
    //int robot_posy;
public:
    //Puzzle(int siz, int x = 1, int y = 1): size(siz), robot_posx(x), robot_posy(y) { }
    Puzzle(int siz, vector<pair<int, int> > lim): size(siz), limits(lim) {}
    int getPathNum(int, int);
};

//the starting point is (posx, posy), assume the destination point is (size, size)
int Puzzle::getPathNum(int posx, int posy)
{
    if(find(limits.begin(), limits.end(), make_pair(posx, posy)) != limits.end())
    {
        return 0; // this is a "off limit" that robot cannot step
    }
    if(posx < size && posy < size)
    {
        return getPathNum(posx + 1, posy) + getPathNum(posx, posy + 1);
    }
    else if(posx == size)
    {
        return getPathNum(posx, posy + 1);
    }
    else if(posy == size)
    {
        return getPathNum(posx + 1, posy);
    }
    else // robot has hit at both walls
    { 
        return 1;
    }
}

int main()
{
    int size = 3;
    //int blockx = 2, blocky = 2;
    vector<pair<int, int> > lim_pair;
    //lim_pair.push_back(make_pair(blockx, blocky));
    lim_pair.push_back(make_pair(2, 2));
    lim_pair.push_back(make_pair(3, 3));
    Puzzle *pzl = new Puzzle(size, lim_pair);
    int posx = 1, posy = 1;
    cout << "Path number for " << size << " x " << size << " puzzle is " << pzl->getPathNum(posx, posy) << endl;
    delete pzl;

    return 0;
}

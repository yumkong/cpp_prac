#include <iostream>
using namespace std;

class Puzzle
{
private:
    int size; // puzzle height and width
    //int robot_posx; 
    //int robot_posy;
public:
    //Puzzle(int siz, int x = 1, int y = 1): size(siz), robot_posx(x), robot_posy(y) { }
    Puzzle(int siz): size(siz) {}
    int getPathNum(int, int);
};

int Puzzle::getPathNum(int posx, int posy)
{
    if(posx < size && posy < size)
    {
        return getPathNum(posx + 1, posy) + getPathNum(posx, posy + 1);
    }
    else // robot has hit at least one wall
    { 
        return 1;
    }
}

int main()
{
    int size = 10;
    Puzzle *pzl = new Puzzle(size);
    int posx = 1, posy = 1;
    cout << "Path number for " << size << " x " << size << " puzzle is " << pzl->getPathNum(posx, posy) << endl;
    delete pzl;

    return 0;
}

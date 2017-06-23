//classic eight queen
#include <iostream>
#include <vector>
using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))

typedef vector<vector<vector<int> > > vvvi;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<int> vi;

class EightQueen
{
private:
    int size;
    vvi chessboard;
    vvb limitboard;
public:
    EightQueen() { }
    EightQueen(int siz, vvi cb, vvb lb): size(siz), chessboard(cb), limitboard(lb) { }
    EightQueen(EightQueen& eq)
    {
        size = eq.size;
        chessboard = eq.chessboard;
        limitboard = eq.limitboard;
    }
    vi check_avail_row(int); // int col_idx
    EightQueen set_queen(int, int); // int row, col
    friend vvvi findEightQueen(EightQueen, int); // what to use obj.size
};

vi EightQueen::check_avail_row(int col_idx)
{
    vi tmp;
    for(int i = 0; i < size; ++i)
    {
        if(limitboard[i][col_idx])
        {
            tmp.push_back(i); 
        }
    }
    return tmp;
}

EightQueen EightQueen::set_queen(int row, int col)
{
    // construct a new obj to store change
    EightQueen tmp(*this);
    // set the chessboard position to 1
    tmp.chessboard[row][col] = 1;
    // set other positions of the same row and column as invalid
    for(int i = 0; i < size; ++i)
    {
        tmp.limitboard[row][i] = false;
        tmp.limitboard[i][col] = false;
    }
    //top-left to bottom-right
    int min_siz = min(row, col);
    //bool quit_loop = false;
    for(int i = row - min_siz, j = col - min_siz; i < size && j < size; ++i, ++j)
    {
        tmp.limitboard[i][j] = false;  
    }
    min_siz = min(row, size - col - 1);
    for(int i = row - min_siz, j = col + min_siz; i < size && j >= 0; ++i, --j)
    {
        tmp.limitboard[i][j] = false;
    }
    return tmp;
}

vvvi findEightQueen(EightQueen eq, int col)
{
    vvvi sumboard;
    //end condition
    if(col == eq.size) //first exceeding chessboard
    {
        sumboard.push_back(eq.chessboard);
    }
    else
    {
        vi avlRow = eq.check_avail_row(col);
        if(!avlRow.empty())
        {
            EightQueen tmp_eq;
            for(vi::iterator iter = avlRow.begin(); iter != avlRow.end(); ++iter)
            {
                int row = *iter;
                // what's this ??? a copy constructor or assignment ?
                tmp_eq = eq.set_queen(row, col);
                vvvi tmpboard = findEightQueen(tmp_eq, col + 1);
                sumboard.insert(sumboard.end(), tmpboard.begin(), tmpboard.end());
            }
        }
    }
    return sumboard;
}

int main()
{
    int siz = 8;
    vvi cb(siz, vector<int>(siz, 0));
    vvb lb(siz, vector<bool>(siz, true)); // initialize all as vacant
    EightQueen eq(siz, cb, lb);
    // starting from 0th column
    vvvi res = findEightQueen(eq, 0);
    int validnum = res.size();
    cout << "there are " << validnum << " valid chessboards: " << endl;
    for(int i = 0; i < 6; ++i)
    {
        vvi tmp = res[i];
        for(int j = 0; j < siz; ++j)
        {
            for(int k = 0; k < siz; ++k)
            {
                cout << tmp[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

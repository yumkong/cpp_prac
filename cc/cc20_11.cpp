//given a square matix, which each cell is filled with either black or white 
// find the maximum subsquare such that all four borders are filled with black pixels
#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 100;
int matrix[MAX_N][MAX_N];

struct Subsquare
{
    int row, col, size;
};

inline int max(int a, int b)
{
    return a > b ? a : b;
}

bool isSquare(int row, int col, int size)
{
    for(int i = 0; i < size; ++i)
    {
       // 1- white,  0- black
       // top border
       if(matrix[row][col + i] == 1) return false;
       // bottom border
       if(matrix[row + size - 1][col + i] == 1) return false;
       // left border
       if(matrix[row + i][col] == 1) return false;
       // right border
       if(matrix[row + i][col + size - 1] == 1) return false;
    }
    return true;
}

Subsquare findSubSquare(int n)
{
    int max_size = 0;
    int col = 0;
    Subsquare sq;
    while(n - col > max_size)
    {
        for(int row = 0; row < n; ++row)
        {
            // at beginning: size = n = 8
            int size = n - max(row, col);
            while(size > max_size)
            {   //(1) 0 0 8, (2) 0 0 7, ...==> 1 0 7, 1 0 6 ,...
                if(isSquare(row, col, size))
                {
                    max_size = size;
                    sq.row = row;
                    sq.col = col;
                    sq.size = size;
                    break;
                }
                --size;
            }
        }
        ++col;
    }
    return sq;
}

int main()
{
    freopen("cc20_11.in", "r", stdin);
    int n;
    cin >> n; // size of the square
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    Subsquare sq = findSubSquare(n);
    cout << "top: " << sq.row << endl;
    cout << "bottom: " << sq.row + sq.size - 1 << endl;
    cout << "left: " << sq.col << endl;
    cout << "right: " << sq.col + sq.size - 1 << endl;
    fclose(stdin);
    return 0;
}

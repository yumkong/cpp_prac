// given a matrix in which each row and each column is sorted, find an element in it
#include <iostream>
#include <cstdio>
using namespace std;

int search(int** a, int row, int col, int x)
{
    int r = 0, c = col - 1; // point to the last elment of the 1st row
    while(r < row && c >= 0)
    {
        if(a[r][c] == x) return (r * col + c);
        else if(a[r][c] < x) ++r; // go to the next row
        else --c; // have located to the right row, begin to pinpoint col idx
    }
    return -1;
}

int main()
{
    freopen("cc9_6.in", "r", stdin);
    int row, col;
    cin >> row >> col;
    int** a = new int*[row];
    for(int i = 0; i < row; ++i)
    {
        a[i] = new int[col];
        for(int j = 0; j < col; ++j)
        {
            cin >> a[i][j]; 
        }
    }

    int k = search(a, row, col, 6);
    if(k == -1) cout << "not found" << endl;
    else cout << "Postion y: " << k / col << ", x: " << k % col << endl;
    fclose(stdin);

    // release memory
    for(int i = 0; i < row; ++i) delete [] a[i];
    delete [] a;
   
    return 0;
}

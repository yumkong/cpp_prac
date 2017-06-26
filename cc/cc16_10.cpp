// function my2DAlloc allocates a 2d array
// minimize the number of calls to malloc and make sure the memory is accessible by arr[i][j]
#include <iostream>
using namespace std;

class my2DAlloc;

class my1DAlloc
{
private:
    int col;
    int *arr;
public:
    // here ok whether it is a friend or not
    //friend my2DAlloc;
    my1DAlloc(int c, int *(&a)): col(c), arr(a) {}
    // better to return a lvalue
    int& operator[](int c)
    {
        if(c >= 0 && c < col) return arr[c];
        else cout << "Invalid col idx = " << c << endl;
    }

};

class my2DAlloc
{
private:
    int **arr;
    int row;
    int col;
public:
    //default
    my2DAlloc(): row(0), col(0), arr(0) {}
    my2DAlloc(int r, int c): row(r), col(c)
    {
        if(row > 0) 
        {
            arr = new int*[row];
            if(col > 0) 
            {             
                arr[0] = new int[row * col];
                for(int i = 1; i < col; ++i) 
                {
                    arr[i] = arr[0] + i * col;
                }
            }
        }
    }
    ~my2DAlloc()
    {
        if(row > 0)
        {
            if(col > 0) delete [] arr[0];
            delete [] arr;
        }
    }
    void set(int y, int x, int val)
    {
        if(y >= 0 && x >= 0 && y < row && x < col) arr[y][x] = val;
        else cout << "Invalid array position row = " << y << ", col = " << x << endl;
    }
    int get(int y, int x)
    {
        if(y >= 0 && x >= 0 && y < row && x < col) return arr[y][x];
        else cout << "Invalid array position row = " << y << ", col = " << x << endl;
    }
    my1DAlloc operator[](int i)
    {
        if(i >= 0 && i < row) 
        {
            return my1DAlloc(col, arr[i]);
        }
        else
        {
            cout << "Invalid col idx = " << i << endl;
        }
    }
};

int main()
{
    int row = 6, col = 6;
    my2DAlloc myarr(row, col);
    for(int i = 0; i < row * col; ++i) myarr.set(i/col, i%col, 16 - i);
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            cout << myarr[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}

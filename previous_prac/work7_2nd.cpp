#include <iostream>
#include <cstring>
using namespace std;
//class Array1;
//class Array2;
class Array1
{
private:
    int *arr;
public:
    Array1(int *_arr):arr(_arr){}
    int &operator[](int idx)
    {
        return arr[idx];
    }
}; // end of Array1

class Array2
{
private:
    int **arr;
public:
    Array2(int **_arr):arr(_arr){}
    Array1 operator[](int idx)
    {
        return Array1(arr[idx]);
    }
};

class Array3 {
private:
    int*** arrPtr;
    int chl, row, col;
public:
    Array3(int _ch = 0, int _r = 0, int _c = 0)
    {
        chl = _ch;
	row = _r;
	col = _c;
	if(chl > 0)
	{
	    arrPtr = new int**[chl];
            if(row > 0)
	    {
		for(int i = 0; i < chl; ++i)
		{
	    	    arrPtr[i] = new int*[row];
                    if(col > 0)
                    {
                        for(int j = 0; j < row; ++j)
                        {
                            arrPtr[i][j] = new int[col];
                        }
                    }
	  	}
	    }
	}
	else
	{
	    arrPtr = NULL;
	}
    }
    Array3 &operator=(Array3 &a)
    {
	if(arrPtr)
	{
	    if(chl > 0)
	    {
		for(int i = 0; i < chl; ++i)
		{
                    for(int j = 0; j < row; ++j)
                    {
                        if(arrPtr[i][j]) delete[] arrPtr[i][j];
                    }
		    if(arrPtr[i]) delete[] arrPtr[i];
		}
	    }
	    delete[] arrPtr;
	}
        chl = a.chl;
	row = a.row;
	col = a.col;
	if(chl > 0)
        {
            arrPtr = new int**[chl];
            if(row > 0)
            {
                for(int i = 0; i < chl; ++i)
                {
                    arrPtr[i] = new int*[row];
                    if(col > 0)
                    {
                        for(int j = 0; j < row; ++j)
                        {
                            arrPtr[i][j] = new int[col];
                            for(int c = 0; c < col; ++c)
                            {
                                arrPtr[i][j][c] = a.arrPtr[i][j][c];
                            }
                        }
                    }
                }
            }
        }
	return *this;
    }
    ~Array3()
    {
	if(arrPtr)
        {
            if(chl > 0)
            {
                for(int i = 0; i < chl; i++)
                {
                    if(row > 0)
                    {
                        for(int j = 0; j < row; ++j)
                        {
                            if(arrPtr[i][j]) delete[] arrPtr[i][j];
                        }
                    }
                    if(arrPtr[i]) delete[] arrPtr[i];
                }
            }
            delete[] arrPtr;
        }

    }
    int operator()(int i, int j, int k)
    {
        return arrPtr[i][j][k];
    }
    Array2 operator[](int idx)
    {
        return Array2(arrPtr[idx]);
    }
}; // end of Array3

int main() 
{
    Array3 a(2,3,4);
    int i, j, k;
    for(k = 0; k < 2; ++k)
    {
        for(i = 0;i < 3; ++i)
        {
            for(j = 0; j < 4; ++j)
            {
                a[k][i][j] = k * 12 + i * 4 + j;
            }
        }
        for(i = 0;i < 3; ++i) 
        {
            for(j = 0; j < 4; ++j)  
            {
                cout << a(k, i, j) << ",";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array3 b;     
    b = a;
    for(k = 0; k < 2; ++k)
    {
        for(i = 0;i < 3; ++i) 
        {
            for(j = 0; j < 4; ++j) 
            {
                cout << b[k][i][j] << ",";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

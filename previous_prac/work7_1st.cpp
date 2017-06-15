#include <iostream>
#include <cstring>
using namespace std;
// define a helper function
class Array1
{
private:
    int *arr;
public:
    Array1(int *_arr):arr(_arr) {}
	int &operator[](int idx)
	{
		return arr[idx];
	}
};

// 2D array class, can use A[row][col], and A(row, col) to get or assign an element
class Array2
{
private:
	int **arrPtr; //2D pointer corresponding to 2D array
	int row, col; // row and col index
public:
    //constructor with default real param
	Array2(int r = 0, int c = 0)
	{
		row = r;
		col = c;
		if(row > 0)
		{
			arrPtr = new int*[row];
			if(col > 0)
			{
				for(int i = 0; i < row; ++i)
				{
					arrPtr[i] = new int[col];
				}
			}
		}
		else
		{
			arrPtr = NULL;
		}
	}
	//reload assign operator
	Array2 &operator=(Array2 &a);
	~Array2();
    Array1 operator[](int idx);
	int operator()(int i, int j);
};

Array2 &Array2::operator=(Array2 &a)
{
	// delete the old arr2 and release space
	if(arrPtr)
	{
		if(col > 0)
		{
			for(int i = 0; i < row; ++i)
			{
				if(arrPtr[i]) 
					delete [] arrPtr[i];
			}
		}
		delete [] arrPtr;
	}
	row = a.row;
	col = a.col;
	if(row > 0)
	{
		arrPtr = new int*[row];
		if(col > 0)
		{
			for(int i = 0; i < row; ++i)
				arrPtr[i] = new int[col];
			for(int r = 0; r < row; ++r)
				for(int c = 0; c < col; ++c)
					arrPtr[r][c] = a.arrPtr[r][c];
		}	
	}
	return *this;
}

Array2::~Array2()
{
	if(arrPtr) // this equals to row > 0
	{
		if(col > 0)
		{
			for(int i = 0; i < row; ++i)
				if(arrPtr[i])
					delete [] arrPtr[i];
		}
		delete [] arrPtr;
	}	
}

Array1 Array2::operator[](int idx)
{
	return Array1(arrPtr[idx]);
}

int Array2::operator()(int i, int j)
{
	return arrPtr[i][j];
}

int main()
{
	Array2 a(3,4);
	int i, j;
	for(i = 0; i < 3; ++i)
		for(j = 0; j < 4; ++j)
			a[i][j] = i * 4 + j;
	for(i = 0; i < 3; ++i)
	{
		for(j = 0; j < 4; ++j)
		{
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
		
	cout << "NEXT" << endl;
	/*All the following 3 are OK, are they of the same meaning? */
	Array2 b = a;
	//Array2 b(a);
	//Array2 b; b = a; // operator= reloading
	for(i = 0; i < 3; ++i)
	{
		for(j = 0; j < 4; ++j)
		{
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}
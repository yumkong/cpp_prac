#include <iostream>
#include <set>
using namespace std;

void setRowColZero(int (&matrix)[4][4])
{
    set<int> rowSet, colSet;
    set<int>::iterator it;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(matrix[i][j] == 0)
            {
                rowSet.insert(i);
                colSet.insert(j);
            }
        }
    }
    // for debug
    cout << "Index for zero rows: ";
    for(it = rowSet.begin(); it != rowSet.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;
    cout << "Index for zero columns: ";
    for(it = colSet.begin(); it != colSet.end(); ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;
    for(int i = 0; i < 4; ++i)
    {
        if(rowSet.find(i) != rowSet.end())
        {
            for(int j = 0; j < 4; ++j) 
            {   matrix[i][j] = 0; }
        }
    }
    for(int j = 0; j < 4; ++j)
    {
        if(colSet.find(j) != colSet.end())
        {
            for(int i = 0; i < 4; ++i)
            {   matrix[i][j] = 0; } 
        }
    }
}

int main()
{
    int dimM = 4, dimN = 4;
    int matrix[4][4] = {{1, 2, 3, 4},{5, 0, 7, 8}, {9, 0, 11, 12}, {13, 14, 15, 66}};
    // print before set zero
    cout << "Original matrix:" << endl;
    for(int i = 0; i < dimM; ++i)
    {
        for(int j = 0; j < dimN; ++j)
        {
            // print
            cout << matrix[i][j];
            if(j + 1 < dimN)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
    // set zeros
    setRowColZero(matrix);
    // print after set zero
    cout << "New matrix:" << endl;
    for(int i = 0; i < dimM; ++i)
    {
        for(int j = 0; j < dimN; ++j)
        {
            // print
            cout << matrix[i][j];
            if(j + 1 < dimN)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
    return 0;
}

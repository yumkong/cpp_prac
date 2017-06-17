// rotate an image by 90 degrees:
// first transpose the Matrix, then swap the column left and right (clockwise)
// or swap the column top and bottom (counter-clockwise)
#include <iostream>
using namespace std;

//helper function
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// here we suppose a clockwise rotation
void rotate90degree(int **a, int dim)
{
    // first transpose
    for(int i = 0; i < dim; ++i)
    {
        // only upper triangle
        for(int j = i+1; j < dim; ++j)
        {
            swap(a[i][j], a[j][i]);
        }
    }
    // then swap the column left and right
    for(int i = 0; i < dim; ++i)
    {
        // integer division is truncation, not floor
        for(int j = 0; j < dim/2; ++j)
        {
            swap(a[i][j], a[i][dim - 1 - j]);
        }
    }
    //return 0;
}

int main()
{
    int dim = 5;
    int **img = new int*[dim];
    // assign value and print
    cout << "orignal image:" << endl;
    for(int i = 0; i < dim; ++i)
    {
        img[i] = new int[dim];
        for(int j = 0; j < dim; ++j)
        {
            // assign
            img[i][j] = i * dim + j;
            // print
            cout << img[i][j];
            if(j + 1 < dim)
            { 
                cout << ", ";
            }
        }
        cout << endl;
    }
    // rotation
    rotate90degree(img, dim);
    // print after rotation
    cout << "rotated image:" << endl;
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            // print
            cout << img[i][j];
            if(j + 1 < dim)
            { 
                cout << ", ";
            }
        }
        cout << endl;
    }
    // release img space
    if(img)  //make sure not NULL pointer
    {
        for(int i = 0; i < dim; ++i)
        {
            if(img[i])
                delete [] img[i];    
        }
        delete [] img;
    }
    return 0;
}

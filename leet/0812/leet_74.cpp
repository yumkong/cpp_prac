// search a 2D matrix
// searches for a value in an m x n matrix
// ints in each row are sorted as ascending order
// the 1st integer of each row is greater than the last int of the previous row
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row <= 0) return false;
        int col = matrix[0].size();
        if(col <= 0) return false;
        int rowmid = row / 2, first = 0, last = row - 1;
        while(first < last)
        {
            if(target < matrix[rowmid][0]) last = rowmid - 1;
            else first = rowmid;
            
            int newrowmid = (first + last)/ 2; 
            // in other words, last = first + 1 ==> will cause dead loop
            if(rowmid == newrowmid)  
            {
                if(target > matrix[newrowmid][col - 1]) {rowmid = last; break;}
                else {rowmid = newrowmid; break;}
            }
            else rowmid = newrowmid; // go to next iteration
        }
        first = 0, last = col - 1;
        int colmid = col / 2;
        while(first < last)
        {
            if(target < matrix[rowmid][colmid]) last = colmid - 1;
            else if(target > matrix[rowmid][colmid]) first = colmid + 1;
            else return true;

            colmid = (first + last)/ 2; 
        }
        return matrix[rowmid][colmid] == target;
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > matrix({vector<int>({1,3,5,7}),
                                 vector<int>({10,11,16,20}),
                                 vector<int>({23,30,34,50})
                                });
    cout << solu.searchMatrix(matrix, 8) << endl;
    return 0;
}

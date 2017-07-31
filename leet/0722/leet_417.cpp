// given an m x n matrix of non-negative ints representing the height of each unit in a continent
// find the list of grid coords where water can flow to both top-left and bottom-right
// m < 150, and n < 150.  Water can flow in 4 directions(up, down, left or right) from a cell to another
// cell with height equal or lower than the former one
#include <vector>
#include <iostream>
#include <utility> //pair
using namespace std;

class Solution {
public:
    vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
        vector<pair<int, int> > res;
        int rowsiz = matrix.size();
        if(rowsiz == 0) return res; // empty pair vector
        // assign to the directions
       // vector<pair<int, int> > directions;
        directions.push_back(make_pair(1, 0)); // bottom
        directions.push_back(make_pair(-1, 0)); // top
        directions.push_back(make_pair(0, 1)); // right
        directions.push_back(make_pair(0, -1)); // left
        int colsiz = matrix[0].size();
        vector<bool> onerow(colsiz, false);
        vector<vector<bool> > p_visited(rowsiz, onerow); // visit pacific
        vector<vector<bool> > a_visited(rowsiz, onerow); // visit atlantic
        //######
        //cout << "come 3" << endl;
        for(int r = 0; r < rowsiz; ++r)
        {
            dfs(matrix, r, 0, p_visited, rowsiz, colsiz);
            dfs(matrix, r, colsiz - 1, a_visited, rowsiz, colsiz);
        }
        //######
        //cout << "come 4" << endl;
        for(int c = 0; c < colsiz; ++c)
        {
            dfs(matrix, 0, c, p_visited, rowsiz, colsiz);
            dfs(matrix, rowsiz - 1, c, a_visited, rowsiz, colsiz);
        }
        //######
        //cout << "come 5" << endl;
        for(int r = 0; r < rowsiz; ++r)
        {
            for(int c = 0; c < colsiz; ++c) 
            {
                if(p_visited[r][c] && a_visited[r][c])
                {
                    res.push_back(make_pair(r, c));
                }
            }
        }
        return res;
    }
    // dfs helper function
    void dfs(vector<vector<int> >& matrix, int r, int c, vector<vector<bool> >& visited, int rowsiz, int colsiz)
    {
        //######
        //cout << "come 6" << endl;
        visited[r][c] = true;
        for(int i = 0; i < directions.size(); ++i)
        {
            int new_r = r + directions[i].first;
            int new_c = c + directions[i].second;
            // trick: the a node is visited, not need to visit it again
            if(new_r < 0 || new_r >= rowsiz || new_c < 0 || new_c >= colsiz || visited[new_r][new_c] || matrix[new_r][new_c] < matrix[r][c])
            {
                // tunnel of stopping recursion
                continue; // visited[new_r][new_c] is false: cannot pass from [r][c] to [new_r][new_c]
            }
            dfs(matrix, new_r, new_c, visited, rowsiz, colsiz);
        }

    }
private: // member val of direction pairs
    vector<pair<int, int> > directions;
};

int main()
{
    int a1[] = {1,2,2,3,5};
    int a2[] = {3,2,3,4,4};
    int a3[] = {2,4,5,3,1};
    int a4[] = {6,7,1,4,5};
    int a5[] = {5,1,1,2,4};
    vector<int> arr1(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    vector<int> arr2(a2, a2 + sizeof(a2)/sizeof(a2[0]));
    vector<int> arr3(a3, a3 + sizeof(a3)/sizeof(a3[0]));
    vector<int> arr4(a4, a4 + sizeof(a4)/sizeof(a4[0]));
    vector<int> arr5(a5, a5 + sizeof(a5)/sizeof(a5[0]));
    vector<vector<int> > matrix;
    matrix.push_back(arr1); 
    matrix.push_back(arr2);
    matrix.push_back(arr3);
    matrix.push_back(arr4);
    matrix.push_back(arr5);
    //######
    //cout << "come 1" << endl;    
    Solution solu;
    vector<pair<int, int> > res = solu.pacificAtlantic(matrix);
    //######
    //cout << "come 2" << endl;
    for(int i = 0; i < res.size(); ++i)
    {
        cout << "[" << res[i].first << ", " << res[i].second << "]" << endl;
    }
    return 0;
}

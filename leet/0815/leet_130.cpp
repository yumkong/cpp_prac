// given a 2D board containing 'X' and 'O' capture all regions surrounded by 'X'
// a region is captured by flipping all 'O's into 'X's in that surrounded region
#include <vector>
#include <iostream>
using namespace std;

class UnionFind {
private:
    int count;
    int* parent;//vector<int> parent;
    int* rank; //vector<int> rank;
public:
    UnionFind(int r, int c, vector<vector<char>>& board) // (int n)
    {
        int num = r * c;
        parent = new int[num];
        rank = new int[num];
        count = num; // n;
        //parent.assign(num, -1); // (n, 0)
        //rank.assign(num, 0); // (n, 0)
        //for(int i = 0; i < count; ++i) parent[i] = i;
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j)
            {
                if(board[i][j] == 'O') 
                {  // when hit border, set as 0
                    if(i == 0 || j == 0 || i == r - 1 || j == c - 1) parent[i * c + j] = 0;
                    else parent[i * c + j] = i * c + j;
                }
                else {parent[i * c + j] = -1; --count;} // X
                rank[i * c + j] = 0;
                //cout << "parent[" << i * c + j << "] = " << parent[i * c + j] << endl;
            }
        }
        count += 1; // all X's is counted as 1
    }
    ~UnionFind()
    {
        delete [] parent;  delete [] rank;
    }
    int find(int p)
    {   // find the leftmost ancestor (root)
        //cout << "ok1, p = " << p << endl;
        if(parent[p] == -1 || parent[p] == 0) return parent[p];
        while(parent[p] != -1 && parent[p] != 0 && p != parent[p])// (p != parent[p])
        {
            parent[p] = parent[parent[p]];
            if(parent[p] == -1 || parent[p] == 0) return parent[p];
            //cout << "ok2, parent[" << p << "] = " << parent[p] << endl; 
            else p = parent[p];
        }
        //cout << "ok2, parent[" << p << "] = " << parent[p] << endl; 
        //cout << "ok2" << endl;
        return parent[p]; //p;
    }
    // cannot use "union" => a key word in c++, use "union_uf" instead
    void union_uf(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        //cout << "ok3, p = " << p << ", rootP = " << rootP << ", rootQ = " << rootQ << endl;
        if(rootP == rootQ) return;
        if(rootP == 0) parent[rootQ] = rootP;
        else if(rootQ == 0) parent[rootP] = rootQ;
        // the larger the rank, the deeper the tree, make smaller tree's root as the deeper tree root
        else if(rank[rootQ] > rank[rootP]) parent[rootP] = rootQ;
        else
        {
            // assign larger number's parents to smaller number
            parent[rootQ] = rootP;
            // at the begining all are zero
            // increase the father node's rank by 1
            if(rank[rootP] == rank[rootQ]) ++rank[rootP];
        } 
        // after done union once, count minus 1
        --count;
    }
    int getCount()
    {
        return count;
    }
    void getMatrix(vector<vector<char>> &board, int row, int col)
    {
        for(int r = 1; r < row - 1; ++r)
        {
            for(int c = 1; c < col - 1; ++c)
            {   //cout << "r = " << r << ", c = " << c << endl;
                if(board[r][c] == 'O' && find(r*col + c) != 0) board[r][c] = 'X';
            }
        }
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row <= 0) return;
        int col = board[0].size();
        if(col <= 0) return;
        //cout << "come1, row = " << row << ", col = " << col << endl;
        UnionFind uf(row, col, board);
        //cout << "come2" << endl;
        for(int r = 1; r < row; ++r)
        {
            for(int c = 1; c < col; ++c)
            { // set all non-border 'O' as 'X'
                if(board[r][c] == 'O')
                {   // assume the element is in row-wise
                    if(board[r-1][c] == 'O') uf.union_uf((r-1)*col + c, r*col + c);
                    if(board[r][c-1] == 'O') uf.union_uf(r*col + c-1, r*col + c);
                }
            }
        }
        //cout << "come3" << endl;
        uf.getMatrix(board, row, col);
    }
};

int main()
{
    //vector<vector<char> > input({vector<char>({'X', 'X', 'X', 'X'}),
    //                             vector<char>({'X', 'O', 'O', 'X'}),
    //                             vector<char>({'X', 'X', 'O', 'X'}),
    //                             vector<char>({'X', 'O', 'X', 'X'}) });
    vector<vector<char> > input({vector<char>({'X','O','X','O','X','O','O','O','X','O'}),
                                 vector<char>({'X','O','O','X','X','X','O','O','O','X'}),
                                 vector<char>({'O','O','O','O','O','O','O','O','X','X'}),
                                 vector<char>({'O','O','O','O','O','O','X','O','O','X'}),
                                 vector<char>({'O','O','X','X','O','X','X','O','O','O'}),
                                 vector<char>({'X','O','O','X','X','X','O','X','X','O'}),
                                 vector<char>({'X','O','X','O','O','X','X','O','X','O'}),
                                 vector<char>({'X','X','O','X','X','O','X','O','O','X'}),
                                 vector<char>({'O','O','O','O','X','O','X','O','X','O'}),
                                 vector<char>({'X','X','O','X','X','X','X','O','O','O'}) });
    Solution solu;
    solu.solve(input);
    //cout << "come 4" << endl;
    for(auto& row: input) 
    { 
        //cout << "come5" << endl;
        for(auto& c: row) cout << c << " ";
        cout << endl;
    }
    return 0;
}

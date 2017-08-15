//given a 2d grid of 1's (land) and 0's (water), count the number of islands
// an island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    int count;
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int r, int c) // (int n)
    {
        count = r * c; // n;
        parent.assign(count, 0); // (n, 0)
        rank.assign(count, 0); // (n, 0)
        for(int i = 0; i < count; ++i) parent[i] = i;
    }
    int find(int p)
    {   // find the leftmost ancestor (root)
        while(p != parent[p])
        {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    // cannot use "union" => a key word in c++, use "union_uf" instead
    void union_uf(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return;
        // the larger the rank, the deeper the tree, make smaller tree's root as the deeper tree root
        if(rank[rootQ] > rank[rootP]) parent[rootP] = rootQ;
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
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row <= 0) return 0;
        int col = grid[0].size();
        if(col <= 0) return 0;
        UnionFind uf(row, col);
        int zeroCnt = 0;
        // top border
        if(grid[0][0] == '0') ++zeroCnt;
        for(int i = 1; i < col; ++i)
        {
            if(grid[0][i] == '0') ++zeroCnt;
            else
            {   // assume the element is in row-wise
                if(grid[0][i - 1] == '1') uf.union_uf(i-1, i);
            }
        }
        // left border
        for(int i = 1; i < row; ++i)
        {
            if(grid[i][0] == '0') ++zeroCnt;
            else
            {   // assume the element is in row-wise
                if(grid[i-1][0] == '1') uf.union_uf((i-1)*col, i*col);
            }
        }
        // all other elements
        for(int r = 1; r < row; ++r)
        {
            for(int c = 1; c < col; ++c)
            {
                if(grid[r][c] == '0') ++zeroCnt;
                else
                {   // assume the element is in row-wise
                    if(grid[r-1][c] == '1') uf.union_uf((r-1)*col + c, r*col + c);
                    if(grid[r][c-1] == '1') uf.union_uf(r*col + c-1, r*col + c);
                }
            }
        }
        return uf.getCount() - zeroCnt;
    }
};

int main()
{
    vector<vector<char> > input({vector<char>({'1', '1', '0', '0', '0'}),
                                 vector<char>({'1', '1', '0', '0', '0'}),
                                 vector<char>({'0', '0', '1', '0', '0'}),
                                 vector<char>({'0', '0', '0', '1', '1'}) });
    Solution solu;
    cout << solu.numIslands(input) << endl;
    return 0;
}

// in union find category
// given N students in a class, M[i][j] = 1 => ith and jth students are friends
// compute how many friend circle are there
#include <vector>
#include <iostream>
using namespace std;

class UnionFind {
private:
    int count;
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n)
    {
        count = n;
        parent.assign(n, 0);
        rank.assign(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
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
    int findCircleNum(vector<vector<int>>& M) {
        int len = M.size();
        if(len <= 1) return 1;
        UnionFind uf(len);
        for(int i = 0; i < len - 1; ++i)
        {
            for(int j = i + 1; j < len; ++j)
            {
                if(M[i][j] == 1) uf.union_uf(i, j);
            }
        }
        return uf.getCount();
    }
};

int main()
{
    vector<vector<int> > input({vector<int>({1,1,0}),
                                vector<int>({1,1,0}),
                                vector<int>({0,0,1}) });
    Solution solu;
    cout << solu.findCircleNum(input) << endl;
    return 0;
}

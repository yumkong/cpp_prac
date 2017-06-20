#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>  //stdin
using namespace std;

//****** consider later, move this globals to main() and use 2d vector to replace 2d array
// max number of vertices
const int MAX_N = 100;
// connection matrix
bool g[MAX_N][MAX_N], visited[MAX_N];
queue<int> q;

void init()
{
    memset(g, false, sizeof(g));
    memset(visited, false, sizeof(visited));
}

bool route(int src, int dst, int n)
{
    // save all nodes that are connect with src
    q.push(src);
    visited[src] = true;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        if(t == dst) return true;
        for(int i = 0; i < n; ++i)
        {
            // use visited[] to avoid push duplicated nodes to queue
            if(g[t][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    //queue is empty without any element being dst
    return false;
}

int main()
{
    init();
    // reuse stdin (a stream) to open the file
    freopen("cc4_2.in", "r", stdin);
    int vertice_num, edge_num, vert1, vert2;
    cin >> vertice_num >> edge_num;
    for(int i = 0; i < edge_num; ++i)
    {
        cin >> vert1 >> vert2;
        // a directed graph, no symmtical edge
        g[vert1][vert2] = true;
    }
    fclose(stdin);
    // whether there is connection between node 0 and node 6
    cout << route(0, 4, edge_num) << endl;
    return 0;
}

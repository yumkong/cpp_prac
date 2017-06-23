#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

enum color
{
    red, yellow, blue, green
};

//??? it seems that bool returns are of no use
bool paint_fill(color **screen, int m, int n, int x, int y, color c)
{
    // exceeding borders, return fasle
    if(x < 0 || x >= m || y < 0 || y >= n) return false;
    if(screen[x][y] == c) return false;
    else
    {
        screen[x][y] = c;
        paint_fill(screen, m, n, x - 1, y, c);
        paint_fill(screen, m, n, x + 1, y, c);
        paint_fill(screen, m, n, x, y - 1, c);
        paint_fill(screen, m, n, x, y + 1, c);
    }
    return true;
}

int main()
{
    freopen("cc8_6.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    color **screen = new color*[m];
    for(int i = 0; i < m; ++i)
    {
        screen[i] = new color[n];
        for(int j = 0; j < n; ++j)
        {
            int t;
            cin >> t;
            screen[i][j] = (color)t;
        }
    }
    cout << "Before color filling:" << endl;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl << "After color filling: " << endl;
    paint_fill(screen, m, n, 1, 2, green);
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
    fclose(stdin);
    return 0;
}

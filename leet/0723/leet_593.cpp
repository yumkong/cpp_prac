// valid square: given 4 coords, check whether they can compose the nodes of a valid square
// valid square: four equal sides with positive length and four equal angles (90)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> edgeleng;
        edgeleng.push_back((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
        edgeleng.push_back((p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]));
        edgeleng.push_back((p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]));
        edgeleng.push_back((p2[0] - p3[0]) * (p2[0] - p3[0]) + (p2[1] - p3[1]) * (p2[1] - p3[1]));
        edgeleng.push_back((p2[0] - p4[0]) * (p2[0] - p4[0]) + (p2[1] - p4[1]) * (p2[1] - p4[1]));
        edgeleng.push_back((p3[0] - p4[0]) * (p3[0] - p4[0]) + (p3[1] - p4[1]) * (p3[1] - p4[1]));
        int longcnt = 0, shortcnt = 0;
        int longsiz = -1, shortsiz = -1;
        for(int i = 0; i < 6; ++i)
        {
            if(edgeleng[i] > longsiz) 
            {
                shortsiz = longsiz;
                shortcnt = longcnt;
                longsiz = edgeleng[i];
                longcnt = 1;
            } 
            else if(edgeleng[i] == longsiz)
            {
                ++longcnt;
            }
            else if(edgeleng[i] > shortsiz)
            {
                shortsiz = edgeleng[i];
                shortcnt = 1;
            }
            else if(edgeleng[i] == shortsiz)
            {
                ++shortcnt;
            }
        } 
        //cout << "longcnt = " << longcnt << ", shortcnt = " << shortcnt << endl;
        //cout << "longsiz = " << longsiz << ", shortsiz = " << shortsiz << endl;
        return (longcnt == 2) && (shortcnt == 4) && (longsiz > 0) && (shortsiz > 0) && (longsiz == 2*shortsiz);
    }
};

int main()
{
    // (4,0)
    vector<int> a1(2,0); a1[0] = 4; a1[1] = 0;
    vector<int> a2(2,0); a2[0] = 7; a2[1] = 4;
    vector<int> a3(2,0); a3[0] = 3; a3[1] = 7;
    vector<int> a4(2,0); a4[0] = 0; a4[1] = 3;    
    Solution solu;
    cout << solu.validSquare(a1, a2, a3, a4) << endl;
    return 0;
}

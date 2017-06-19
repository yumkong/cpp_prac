#include <iostream>
#include <stack>
using namespace std;

struct op
{
    //begin: smallest disk number, end: largest disk number
    int begin, end;
    //src: src rod, bri: bridging rod, dst: destination rod
    char src, bri, dst;
    op() {}
    // The meaning of this struct: send the disks (range from begin to end) from src to dst via bri
    op(int pb, int pe, int ps, int pbri, int pd):begin(pb), end(pe), src(ps), bri(pbri), dst(pd) {}
};

void hanoi(int n, char src, char bri, char dst)
{
    stack<op> st;
    op tmp;
    st.push(op(1, n, src, bri, dst));
    while(!st.empty())
    {
        // pop from stack top to tmp
        tmp = st.top();
        st.pop();
        if(tmp.begin != tmp.end)
        {
            // do the three things one after another
            // the 3rd thing (put the n-1 diskes in bridging rod to dst via src)
            st.push(op(tmp.begin, tmp.end - 1, tmp.bri, tmp.src, tmp.dst));
            // the 2nd thing (put the biggest disk to dst directly)
            st.push(op(tmp.end, tmp.end, tmp.src, tmp.bri, tmp.dst));
            // the 1st thing: (put the n-1 diskes tmperarily to bridging rod) 
            st.push(op(tmp.begin, tmp.end - 1, tmp.src, tmp.dst, tmp.bri));
        }
        else
        {
            cout << "moving " << tmp.begin << " from " << tmp.src << " to " << tmp.dst << endl;
        }
    }
}

int main()
{
    hanoi(3, 'A', 'B', 'C');
    return 0;
}

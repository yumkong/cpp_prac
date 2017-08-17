// find number of reverse pairs:
// given an array nums, we call (i, j) an important reverse pair if i < j
// and nums[i] > 2 * nums[j], find the number of all such pairs
// solu1: binary search tree => TLE

#include <iostream>
#include <vector>
using namespace std;
// the following 3 funcs can be used to other bst problem
class Node
{
public:
    Node *left, *right;
    int val;
    int count_ge; // record how many nodes are >= root node
    // THE NODE	itself is greater or equal to itself
    Node(int v): val(v), count_ge(1), left(NULL), right(NULL) {}
};

Node* insert(Node *head, int val)
{
    //cout << "insert val = " << val << endl;
    if(!head) return new Node(val);
    else if(val == head->val) ++(head->count_ge);
    else if(val < head->val) head->left = insert(head->left, val);
    else if(val > head->val) {++(head->count_ge); head->right = insert(head->right, val); }
    return head;
}

int search(Node* head, long long target)
{
    if(!head) return 0;
    else if(target == head->val) return head->count_ge;
    else if(target < head->val) return head->count_ge + search(head->left, target);
    else return search(head->right, target);
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        Node* head = NULL;
	int n = nums.size();
	int count = 0;
	for(int i = 0; i < n; ++i)
	{
	    // find how many proceding numbers satisfies num[pro] >= 2* num[cur] + 1
	    count += search(head, nums[i] * 2LL + 1);
	    head = insert(head, nums[i]); // adding current nums to tree
	}
	return count;
    }
};

int main()
{
    Solution solu;
    vector<int> input({2,4,3,5,1});
    cout << solu.reversePairs(input) << endl;
    return 0;
}

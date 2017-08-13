// implement a trie (prefix tree) with insert, search, and startsWith methods
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
private:
    char ch;
    bool isEnd;
    vector<TrieNode *> children; // empty
    friend class Trie; // only in this way can isEnd and children be used in Trie
public:
    //construct
    TrieNode(): ch(' '), isEnd(false) {}  // use to init trie root
    TrieNode(char c): ch(c), isEnd(false) {}
    TrieNode* containNode(char c) 
    { 
        if(!children.empty())
        {
            for(auto &child: children)
            {
                if(child->ch == c) return child;
            }
        }
        return NULL;
    }
    ~TrieNode()
    {
        for(auto &child : children) delete child;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        // if already exist
        if(search(word)) return;
        // always start constructing from root
        TrieNode* cur = root; 
        for(auto &c: word)
        {
            TrieNode* child = cur->containNode(c);
            if(child != NULL) cur = child;
            else
            {
                TrieNode *newNode = new TrieNode(c);
                cur->children.push_back(newNode);
                cur = newNode; // next avaliable row idx
            }
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        // always start constructing from root
        TrieNode* cur = root; 
        for(auto &c: word)
        {
            cur = cur->containNode(c);
            // if cur == NULL
            if(!cur) return false;
        }
        return cur->isEnd == true; // if all letter positions are occupied and last letter is an end letter
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // always start constructing from root
        TrieNode* cur = root;
        for(auto &c: prefix)
        {
            cur = cur->containNode(c);
            if(!cur) return false;
        }
        return true; // if all letter positions are occupied
    }
    ~Trie() { delete root; }
};

int main()
{
    Trie obj;
    obj.insert("algorithm");
    obj.insert("math");
    cout << obj.search("wow") << endl;
    cout << obj.startsWith("mat") << endl;
    return 0;
}

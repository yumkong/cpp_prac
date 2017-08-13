// design data structure supporting add and search word
// when searching word, it only contains letters a - z or '.' , which represents any one letter
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
private:
    char ch;
    bool isEnd;
    vector<TrieNode *> children; // empty
    friend class WordDictionary; // only in this way can isEnd and children be used in Trie
public:
    //construct
    TrieNode(): ch(' '), isEnd(false) {}  // use to init trie root
    TrieNode(char c): ch(c), isEnd(false) {}
    TrieNode* subNode(char c) 
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

class WordDictionary{
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if(search(word)) return;
        TrieNode *cur = root;
        for(auto &c: word)
        {
            TrieNode* child = cur->subNode(c);
            if(child) cur = child;
            else
            {
                TrieNode *newNode = new TrieNode(c);
                cur->children.push_back(newNode);
                cur = newNode;
            }
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return query(word.c_str(), root);
    }
private:
    // note here c-style string is more efficient
    bool query(const char* word, TrieNode* root)
    {
        TrieNode *cur = root;
        // word[i] is checking whether '\0' is reached
        for(int i = 0; word[i]; ++i)
        {
            //cout << "children size = " << cur->children.size() << endl;
            if(word[i] == '.')
            {
                if(cur->children.empty()) return false;
                for(auto& tmp: cur->children)
                {  
                    cur = tmp;
                    if(query(word + i + 1, cur)) return true;
                }
            }
            else
            {
                cur = cur->subNode(word[i]);
                if(!cur) break;
            }
        }
        return cur && cur->isEnd;
    }
};

int main()
{
    WordDictionary obj;
    obj.addWord("a");
    obj.addWord("a");
    cout << obj.search(".a") << endl;
    cout << obj.search("a.") << endl;
    return 0;
}

#include <cstring>

const int kWordSize = 26 + 5;
const int kNodeSize = 1200 + 5;
const int kHashSize = 10001; // big prime

typedef unsigned int uint;

struct Node
{
    char word[kWordSize];
    Node *next;
};

Node node[kNodeSize + 1]; // is the database for all strings
Node* head[kHashSize + 1];

class Hash
{
private:
    uint seed;
    uint size;
public:
    Hash();
    uint hash(const char* str);
    void insert(const char* str);
    bool find(const char* str);
};
 
Hash::Hash(): seed(131), size(0)
{
    memset(head, 0, sizeof(head));
}

// hash func to compute the address according to key value
// return the hash address
uint Hash::hash(const char* str)
{
    uint hash = 0;
    // first get a char *str, then forward the pointer str++
    while(*str++)  hash = hash * seed + (*str);
    return (hash & 0x7fffffff) % kHashSize;
}

void Hash::insert(const char* str)
{
    uint id = hash(str);
    // size the address of the last available node's index 
    // this node is not used yet
    // dst points to the 1st char of this node's word (uninitialized)
    char *dst = (char *)node[size].word;
    while(*dst++ = *str++); // assign the whole word
    node[size].next = head[id]; // point to null (0)
    head[id] = &node[size]; // points to this new node (node array's tail)
    ++size; // incre the number of avail node
}

bool Hash::find(const char* str)
{
    uint id = hash(str);
    for(Node *p = head[id]; p; p = p->next)
    {
        // dst points to the hashtable database's corresponding word (based on the address)
        char *dst = (char *)p->word;
        int i = 0;
        // compare the database string with the query string
        while(*(str + i) && *(dst + i) == *(str + i))
        {
            ++i;
        }
        // two string are of the same length
        if(*(str + i) == '\0' && *(dst + i) == '\0') return true;
    }
    return false;
}




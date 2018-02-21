#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct TrieNode
{
    TrieNode * m_children[26];
    bool m_word;
    
    TrieNode() : m_word(false)
    {
        for (int i = 0; i < 26; ++i)
        {
            m_children[i] = NULL;
        }
    }
    
    void getAllWords(vector<string>& res, const string& prefix);
};

void TrieNode::getAllWords(vector<string>& res, const string& prefix)
{
    if (m_word)
    {
        res.push_back(prefix);
    }
    
    for (int i = 0; i < 26; ++i)
    {
        if (m_children[i] != NULL)
        {
            ostringstream oss;
            oss << prefix << (char)('a' + i);
            m_children[i]->getAllWords(res, oss.str());
        }
    }
}

struct Trie
{
    TrieNode * m_root;
    
    Trie() : m_root(new TrieNode()) {};
    
    void insert(const string& w);
    
    bool findWord(const string& w);
    
    vector<string> findMatchPrefixWord(const string& prefix);
};

void Trie::insert(const string& w)
{
    TrieNode * cur = m_root;
    
    for (auto a : w)
    {
        if (cur->m_children[a - 'a'] == NULL)
        {
            cur->m_children[a - 'a'] = new TrieNode();
        }
        
        cur = cur->m_children[a - 'a'];
    }
    
    cur->m_word = true;
}

bool Trie::findWord(const string& w)
{
    TrieNode * cur = m_root;
    for (auto a : w)
    {
        if (cur->m_children[a - 'a'] == NULL)
            return false;
        
        cur = cur->m_children[a - 'a'];
    }
    
    return cur->m_word;
}

vector<string> Trie::findMatchPrefixWord(const string& prefix)
{
    vector<string> res;
    TrieNode * cur = m_root;
    for (auto a : prefix)
    {
        if (cur->m_children[a - 'a'] == NULL)
            return res;
        
        cur = cur->m_children[a - 'a'];
    }
    cur->getAllWords(res, prefix);
    
    return res;
}

Trie * buildTree()
{
    Trie * t = new Trie();
    
    t->insert("aaa");
    t->insert("aab");
    t->insert("acc");
    
    return t;
}

void print(const vector<string> & v)
{
    for (auto a : v)
        cout << a << " ";
    
    cout << endl;
}

int main(int argc, char** argv) {

    Trie * t = buildTree();
    
    vector<string> res = t->findMatchPrefixWord("aa");
    
    print(res);
    
    return 0;
}


/*
Implement Trie (Prefix Tree)

Implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:
You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
class TrieNode
{
    public:
    bool eow;
    TrieNode* children[26];
    
    TrieNode() {
        eow = false;
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
          //  ->eow = false;
        //for(int i=0; i<26; i++)
        //    root->children[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *pCrawl = root;
        for(int i=0; i<word.length(); i++)
        {
            if(!pCrawl->children[word[i]-'a'])
                pCrawl->children[word[i]-'a'] = new TrieNode();
            pCrawl = pCrawl->children[word[i]-'a'];
        }
        pCrawl->eow = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *pCrawl = root;
        for(int i=0; i<word.length(); i++)
        {
            if(!pCrawl->children[word[i]-'a'])
                return false;
            pCrawl = pCrawl->children[word[i]-'a'];
        }
        if(pCrawl->eow)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *pCrawl = root;
        for(int i=0; i<prefix.length(); i++)
        {
            if(!pCrawl->children[prefix[i]-'a'])
                return false;
            pCrawl = pCrawl->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

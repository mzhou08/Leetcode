#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    public:
    bool is_leaf;
    vector<TrieNode*> next;

    TrieNode() {
        is_leaf = false;

        next = vector<TrieNode*>(26);
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        clear(root);
    }
    
    void insert(string word) {
        // have to use iterative because the Trie stores TrieNode*

        TrieNode* currNode = root;

        for (char c: word) {
            int char_num = int(c) - int('a');
            if (!currNode->next[char_num]) {
                currNode->next[char_num] = new TrieNode();
            }
            currNode = currNode->next[char_num];
        }

        currNode->is_leaf = true;
    }
    
    bool search(string word) {
        TrieNode* currNode = root;

        int char_num;
        for (char c: word) {
            char_num = int(c) - int('a');
            if (currNode->next[char_num] == nullptr) {
                return false;
            }
            currNode = currNode->next[char_num];
        }

        return (currNode->is_leaf);
    }
    
    bool startsWith(string prefix) {
        TrieNode* currNode = root;

        int char_num;
        for (char c: prefix) {
            char_num = int(c) - int('a');
            if (currNode->next[char_num] == nullptr) {
                return false;
            }
            currNode = currNode->next[char_num];
        }

        return true;
    }
    
private:
    void clear (TrieNode* node) {
        for (TrieNode* nextNode: node->next) {
            if (nextNode) {
                clear(nextNode);
            }
        }
        
        delete node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
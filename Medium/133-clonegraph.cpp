#include <vector>
#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cgHelper(Node* node, unordered_map<int, Node*>& clones) {
        if (node == nullptr) {
            return nullptr;
        } else if (clones.find(node->val) != clones.end()) {
            // Node has already been seen
            return clones[node->val];
        }
        
        Node* clone = new Node(node->val);

        clones[node->val] = clone;
        
        for (Node* nbor: node->neighbors) {
            clone->neighbors.push_back(cgHelper(nbor, clones));
        }
        
        return clone;
    }
    
    Node* cloneGraph(Node* node) {        
        unordered_map<int, Node*> clones;
        
        return cgHelper(node, clones);
    }
};
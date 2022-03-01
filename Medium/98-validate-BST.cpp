#include <cstddef>

/* Runtime: 17 ms, faster than 52.79% of C++ online submissions for Validate Binary Search Tree.
   Memory Usage: 21.5 MB, less than 99.10% of C++ online submissions for Validate Binary Search Tree.
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool BSTBound (TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) return true;
        
        return BSTBound (root->left, min, root) && BSTBound (root->right, root, max) && (max == nullptr || root->val < max->val) && (min == nullptr || root->val > min->val);
    }
    
    bool isValidBST(TreeNode* root) {
        return BSTBound (root, nullptr, nullptr);
    }
};
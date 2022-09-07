/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<bool, int> isBalancedDepth(TreeNode *root) {
        if (root == nullptr) {
            return make_pair(true, 0);
        }
        
        auto [rbal, rdepth] = isBalancedDepth(root->right);
        auto [lbal, ldepth] = isBalancedDepth(root->left);
        
        bool depthcheck = abs(rdepth - ldepth) <= 1;
        
        return make_pair((rbal && lbal) && depthcheck, max(rdepth, ldepth) + 1);
    }
    
    bool isBalanced(TreeNode* root) {
        auto [isbal, _] = isBalancedDepth(root);
            
        return isbal;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if ((p->val) < (root->val) && (q->val) < (root->val)) {
            // both on right side
            return lowestCommonAncestor(root->left, p, q);
        } else if ((p->val) > (root->val) && (q->val) > (root->val)) {
            // both on left side
            return lowestCommonAncestor(root->right, p, q);
        } else {
            // slit point, or one of them is equal to root->val
            return root;
        }
    }
};
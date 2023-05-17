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
private:
    TreeNode *lca;

    bool lcaHelp(TreeNode *root, TreeNode *p, TreeNode *q) {
        // does p appear does q appear, or both, or none in this subtree?
        // false: neither appears, true: one or both appeared

        if (root == NULL) {
            // base case
            return false;
        } else if (root == p || root == q) {
            bool leftRes = lcaHelp(root->left, p, q);
            bool rightRes = lcaHelp(root->right, p, q);

            // if q in subtrees, then LCA is root
            if (leftRes || rightRes) {
                lca = root;
                return true;
            }

            // else LCA is still above, return found p
            return true;
        } else {
            bool leftRes = lcaHelp(root->left, p, q);
            bool rightRes = lcaHelp(root->right, p, q);

            // look in left subtree
            // if left subtree has LCA, then return left res
            if (leftRes ^ rightRes) return true;

            // if l has p and R has q, or vice versa, return root
            if (leftRes && rightRes) {
                lca = root;
                return true;
            }
            // else, return whichever one of p and q was found from root
            return false;
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lcaHelp(root, p, q);
        return lca;
    }
};
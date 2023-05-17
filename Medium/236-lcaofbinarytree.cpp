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
    pair<long, TreeNode *> lcaHelp(TreeNode *root, TreeNode *p, TreeNode *q) {
        // does p appear does q appear, or both, or none in this subtree?
        // 0: NONE, 1: P ONLY, 2: Q ONLY, 3: BOTH

        if (root == NULL) {
            // base case
            pair<int, TreeNode *> res = make_pair(0, root);
            return res;
        } else if (root == p) {
            pair<int, TreeNode*> leftRes = lcaHelp(root->left, p, q);
            pair<int, TreeNode*> rightRes = lcaHelp(root->right, p, q);

            // if q in subtrees, then LCA is root
            if (leftRes.first == 2 || rightRes.first == 2) {
                return make_pair(3, root);
            }

            // else LCA is still above, return found p
            return make_pair(1, root);
        } else if (root == q) {
            pair<int, TreeNode*> leftRes = lcaHelp(root->left, p, q);
            pair<int, TreeNode*> rightRes = lcaHelp(root->right, p, q);

            // if p in subtrees, then LCA is root
            if (leftRes.first == 1 || rightRes.first == 1) {
                return make_pair(3, root);
            }
            // else LCA is still above, return found q
            return make_pair(2, root);
        } else {
            pair<int, TreeNode*> leftRes = lcaHelp(root->left, p, q);
            pair<int, TreeNode*> rightRes = lcaHelp(root->right, p, q);

            // look in left subtree
            // if left subtree has LCA, then return left res
            if (leftRes.first == 3) {
                return leftRes;
            }

            // look in right subtree
            // if right subtree has LCA, then return right res
            if (rightRes.first == 3) {
                return rightRes;
            }

            // if l has p and R has q, or vice versa, return root
            if (leftRes.first + rightRes.first == 3) {
                return make_pair(3, root);
            }
            // else, return whichever one of p and q was found from root
            return make_pair(max(leftRes.first, rightRes.first), root);
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lcaHelp(root, p, q).second;
    }
};
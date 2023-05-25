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
    vector<int> rightSideView(TreeNode* root) {
        // recursive approach
        // BC: if null, return []
        if (root == NULL) {
            return {};
        }
        // Inductive Case:
        vector<int> rightRes = rightSideView(root->right);
        vector<int> leftRes = rightSideView(root->left);

        // root is always in the right side view
        vector<int> res = {root->val};

        // res contains all from rightres
        for (int i = 0; i < rightRes.size(); i++) {
            res.push_back(rightRes[i]);
        }

        // push remaining left view onto the res
        for (int i = rightRes.size(); i < leftRes.size(); i++) {
            res.push_back(leftRes[i]);
        }

        return res;


    }
};
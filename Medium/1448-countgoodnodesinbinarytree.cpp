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
typedef pair<TreeNode*, int> pti;

class Solution {
public:
    int bfs(TreeNode* root) {

        if (root == NULL) return 0;

        queue<pti> q = {};
        q.push(
            make_pair(root, root->val)
        );

        int goodNodes = 0;

        while (!q.empty()) {
            pti front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int maxVal = max(front.second, node->val);

            if (node->val >= maxVal) {
                goodNodes++;
            }

            if (node->left != NULL) {
                q.push(
                    make_pair(
                        node->left,
                        max(maxVal, node->left->val)
                    )
                );
            }

            if (node->right != NULL) {
                q.push(
                    make_pair(
                        node->right,
                        max(maxVal, node->right->val)
                    )
                );
            }
        }

        return goodNodes;
    }

    int goodNodes(TreeNode* root) {
        /**
        We can do this by storing, for each X:
            the max value seen from root to X.
            maxValue(X) = max(X.val, maxValue(X.par))

        if X.val >= maxVal(X.par)
            res++;
        */

        return bfs(root);
    }
};
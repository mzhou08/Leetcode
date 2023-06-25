/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void dfs(TreeNode* root, string& acc) {
        if (root == NULL) {
            // add 1001 because the vals are guaranteed
            // to be <= 1000
            acc += "1001 ";
            return;
        }

        acc += to_string(root->val) + " ";

        dfs(root->left, acc);
        dfs(root->right, acc);

        return;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";

        dfs(root, res);
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss = istringstream(data);

        string s;

        // stack tracking parent nodes, and whether
        // the left has been set or not
        vector<pair<TreeNode*, bool>> parents = {};
        TreeNode* par = NULL;

        while (getline(ss, s, ' ')) {
            if (s.size() != 0) {
                int val = stoi(s);

                TreeNode* curr = NULL;

                if (val == 1001) {
                    // NULL
                    curr = NULL;
                    
                    // set parent, and propagate up
                    while (!parents.empty()) {
                        // pop from parents
                        pair<TreeNode*, bool> top = parents.back();

                        par = top.first;
                        bool leftSet = top.second;

                        if (leftSet) {
                            par->right = curr;
                            
                            // both children have been set
                            parents.pop_back();

                            // keep moving upwards
                            curr = par;
                        } else {
                            par->left = curr;

                            // left child has been set
                            parents.back() = make_pair(par, true);
                            
                            // only left has been set, stop here
                            break;
                        }
                    }
                } else {
                    curr = new TreeNode(val);

                    parents.push_back(make_pair(curr, false));
                }
            }
        }

        // par should be set to root when the loop breaks
        return par;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void gn(TreeNode* root, int n) {
        if (root == NULL) {
            return;
        }
        
        if (root->val >= n) {
            ans++;
        }
        gn(root->left, max(n, root->val));
        gn(root->right, max(n, root->val));
        return;
    }

    int goodNodes(TreeNode* root) {
        gn(root, root->val);
        return ans;
    }
};
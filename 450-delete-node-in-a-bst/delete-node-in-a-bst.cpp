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
    // void dfs(TreeNode*& root, int key) {
    //     if (root == NULL) {
    //         return;
    //     }
    //     if (root->val == key) {
    //         if (root->right == NULL && root->left == NULL) {
    //             root = NULL;
    //             return;
    //         }
    //         if (root->right == NULL) {
    //             root = root->left;
    //             return;
    //         }
    //         if (root->left == NULL) {
    //             root = root->right;
    //             return;
    //         }

    //         TreeNode* temp = root->left;
    //         while (temp->right != NULL) {
    //             temp = temp->right;
    //         }
    //         temp->right = root->left;
    //         root=root->right;
    //         return;
    //     }
    //     if (key < root->val) {
    //         dfs(root->left, key);
    //     } else {
    //         dfs(root->right, key);
    //     }
    //     return;
    // }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return NULL;
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else {
            if (!root->right && !root->left)
                return NULL;
            else if (!root->right)
                return root->left;
            else if (!root->left)
                return root->right;
            else {
                TreeNode* temp = root->right;
                while (temp->left)
                    temp = temp->left;
                temp->left = root->left;
                return root->right;
            }
        }
        return root;
    }
};
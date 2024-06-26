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
    void lvs(TreeNode* root, vector<int> &v) {
        if(root==NULL)
        {
            return;
        }
         if (root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
            return;
        }
       
        lvs(root->left, v);
        lvs(root->right, v);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        lvs(root1, v1);
        lvs(root2, v2);
        for(auto it :v1)
        {
            cout<<it<<" ";
        }
         for(auto it :v2)
        {
            cout<<it<<" ";
        }
        return (v1 == v2);
    }
};
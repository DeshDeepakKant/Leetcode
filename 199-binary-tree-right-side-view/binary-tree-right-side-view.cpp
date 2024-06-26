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
    vector<int> ans;
    void dfs(TreeNode* root,int n)
    {
        if(root==NULL)
        {
            return;
        }
        if(n+1>ans.size())
        {
            ans.push_back(root->val);
        }
        else
        {
            ans[n]=root->val;
        }
        dfs(root->left,n+1);
        dfs(root->right,n+1);
        return;

    }


    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};
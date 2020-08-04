// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

// solution:
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
    int ans;
    int maxpath(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int L=max(0,maxpath(root->left));
        int R=max(0,maxpath(root->right));
        ans=max(ans,L+R+root->val);
        return max(L,R)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        ans=root->val;
        maxpath(root);
        return ans;
    }
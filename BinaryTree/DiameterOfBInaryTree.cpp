// Link: https://leetcode.com/problems/diameter-of-binary-tree/

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
    int ans=0;
    int diameter(TreeNode* root)
    {
         if(!root)
            return 0;
        int L=diameter(root->left);
        int R=diameter(root->right);
        ans=max(ans,L+R+1);
        return max(L,R)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root)
            return 0;
        diameter(root);
        return ans-1;
    }
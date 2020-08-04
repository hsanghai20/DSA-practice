// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        if(root->left!=NULL)
        {
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=NULL;
            while(root->right!=NULL)
                root=root->right;
            root->right=temp;
        }
    }
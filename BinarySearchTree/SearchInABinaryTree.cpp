// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;
        if(root->val==val)
            return root;
        else if(root->val<val)
            return searchBST(root->right,val);
        else
            return searchBST(root->left,val);
    }
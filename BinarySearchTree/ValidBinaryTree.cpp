// Link: https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isvalid(TreeNode* root,long long L,long long R)
    {
        if(!root)
            return true;
        if(root->val<=L)
            return false;
        if(root->val>=R)
            return false;
        return isvalid(root->left,L,root->val)&&isvalid(root->right,root->val,R);
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root,-2147483649,2147483648);
    }

// solution : we can do inorder traversal and check whether the inorder is in ascending order or not if not return false
// because we know that in bst inorder is always in ascending order
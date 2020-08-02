// Link: https://leetcode.com/problems/balanced-binary-tree/

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

    bool flag=true;
    int balanced(TreeNode* root)
    {
        if(!root)
            return 0;
        int heightleft=1+balanced(root->left);
        int heightright=1+balanced(root->right);
        if(abs(heightright-heightleft)>1)
            flag=false;
        return max(heightright,heightleft);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        balanced(root);
        return flag;
    }

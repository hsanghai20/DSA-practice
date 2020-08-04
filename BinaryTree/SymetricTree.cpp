// Link: https://leetcode.com/problems/symmetric-tree/

// solution(iterative)
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
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        queue<TreeNode*> qleft,qright;
        if(!root->left && !root->right)
            return true;
        if(!root->left || !root->right)
            return false;
        qleft.push(root->left);
        qright.push(root->right);
        while(!qleft.empty() && !qright.empty())
        {
            TreeNode* lefttemp=qleft.front();
            TreeNode* righttemp=qright.front();
            qleft.pop();
            qright.pop();
            if(!lefttemp && !righttemp)
                continue;
            if(!lefttemp || !righttemp)
                return false;
            if(lefttemp->val!=righttemp->val)
                return false;
            qleft.push(lefttemp->left);
            qleft.push(lefttemp->right);   
            qright.push(righttemp->right);
            qright.push(righttemp->left);  
        }
        if(qleft.size()==0 && qright.size()==0)
            return true;
        return false;
    }
};

// solution(recursive)
    bool issymetric(TreeNode* rleft,TreeNode* rright)
    {
        if(!rleft && !rright)
            return true;
        if(!rleft || !rright)
            return false;
        return (rleft->val==rright->val) && issymetric(rleft->left,rright->right) && issymetric(rleft->right,rright->left);
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        return issymetric(root,root);
    }

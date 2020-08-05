// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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

    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> s;    
        TreeNode* temp=root;
        while(!s.empty() || temp!=NULL)
        {
            while(temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
            }
            temp=s.top();
            s.pop();
            if(--k==0)return temp->val;
            temp=temp->right;
        }
        return -1;
    }
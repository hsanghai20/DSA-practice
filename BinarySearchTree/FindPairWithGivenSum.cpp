// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL && k!=0)
            return false;
        if(root==NULL && k==0)
            return true;
        set<int> s;
        queue <TreeNode* > q;
        q.push(root);
        TreeNode* temp=root;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(s.find(k-temp->val)==s.end())
                s.insert(temp->val);
            else
                return true;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return false;
    }

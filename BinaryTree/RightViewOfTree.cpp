// Link: https://leetcode.com/problems/binary-tree-right-side-view/

// Given a binary tree, imagine yourself standing on the right side of it,
//  return the values of the nodes you can see ordered from top to bottom.


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
vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        queue <TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty())
        {
            int x=q.size();
            while(x!=0)
            {
                temp=q.front();
                if(x==1)
                {
                    ans.push_back(temp->val);
                }
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                x--;
            }
        }
        return ans;
    }
// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> s;
        s.push(root);
        int count=0;
        TreeNode* temp;
        while(!s.empty())
        {
            int x=s.size();
            count++;
            vector<int> col;
            while(x--)
            {
                temp=s.front();
                s.pop();
                if(temp->left)
                    s.push(temp->left);
                if(temp->right)
                    s.push(temp->right);
                col.push_back(temp->val);
            }
            if(count%2==0)
            {
                reverse(col.begin(),col.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
// Link:   https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* makeTree(vector<int>& nums,int L,int R)
    {
        if(L>R)
            return NULL;
        int mid=(L+R)/2;
        TreeNode* temp=new TreeNode(nums[mid]);
        temp->left=makeTree(nums,L,mid-1);
        temp->right=makeTree(nums,mid+1,R);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums){
        return makeTree(nums,0,nums.size()-1);
    }
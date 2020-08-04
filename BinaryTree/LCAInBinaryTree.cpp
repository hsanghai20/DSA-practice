// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// solution:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    int pflag=0,qflag=0;
    vector<TreeNode*> ppath,qpath;
    void pplace(TreeNode* root,TreeNode* p)
    {
        if(root==NULL || pflag)
            return;
        if(root==p)
        {
            ppath.push_back(root);
            pflag=1;
            return;
        }
        if(pflag==0)
        {
            ppath.push_back(root);
            pplace(root->left,p);
            if(pflag==1)
                return;
            pplace(root->right,p);
            if(pflag==1)
                return;
            ppath.pop_back();   
        }
    }
    void qplace(TreeNode* root,TreeNode* q)
    {
        if(root==NULL || qflag)
            return;
        if(root==q)
        {
            qpath.push_back(root);
            qflag=1;
            return;
        }
        if(qflag==0)
        {
            qpath.push_back(root);
            qplace(root->left,q);
            if(qflag==1)
                return;
            qplace(root->right,q);
            if(qflag==1)
                return;
            qpath.pop_back();   
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pplace(root,p);
        qplace(root,q);
        int x=ppath.size(),y=qpath.size();
        for(int i=min(x,y)-1;i>=0;i--)
        {
            if(ppath[i]==qpath[i])
                return ppath[i];
        }
        return NULL;
    }


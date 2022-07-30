class Solution {
public:
    vector<vector<int>>v;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
        {
            return v;
        }
        queue<TreeNode*>q;
        int i; bool flag=false;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>tempvec;
            for(i=0;i<n;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                tempvec.push_back(temp->val);
                if(temp->left!=NULL) q.push(temp->left); 
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(flag)
            {
                reverse(tempvec.begin(),tempvec.end());
            }
            flag=!flag;
            v.push_back(tempvec);  
        }
        return v;
    }
};

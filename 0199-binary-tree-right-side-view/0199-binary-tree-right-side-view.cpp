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
    void recursion(TreeNode* root, int level, vector<int> &ans){
        if(root == NULL)    return;
        if(ans.size()==level)   ans.push_back(root->val);
        recursion(root->right,level+1,ans);
        recursion(root->left,level+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recursion(root,0,ans);
        return ans;
    /*My own solution----**
        vector<int> ans;
        if(root==NULL)  return ans;
        map<int,int> mp;
        stack<pair<TreeNode*,int>> st;
        st.push({root,0});
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            TreeNode* node = it.first;
            int level = it.second;
            mp[level] = node->val;
            if(node->right)     st.push({node->right,level+1});
            if(node->left)      st.push({node->left,level+1});
        }
        for(auto it : mp)
            ans.push_back(it.second);
        return ans;
    ******/
    }
};
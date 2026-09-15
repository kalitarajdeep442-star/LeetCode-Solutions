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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& postorder, int poststart, int postend, vector<int>& inorder, int instart, int inend, map<int,int>& mp){
        if(poststart>postend || instart>inend)    return NULL;
        TreeNode* root = new TreeNode(postorder[postend]);
        int inRoot = mp[root->val];
        int numsleft = inRoot - instart;
        root->left = buildTree(postorder, poststart, poststart+numsleft-1, inorder, instart, inRoot-1, mp);
        root->right = buildTree(postorder,poststart+numsleft, postend-1, inorder, inRoot+1, inend, mp);
        return root;
    }
};
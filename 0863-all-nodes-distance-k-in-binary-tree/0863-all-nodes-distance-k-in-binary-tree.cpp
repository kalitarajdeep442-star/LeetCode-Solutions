/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentTrack){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parentTrack[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parentTrack[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        mark_parent(root,parentTrack);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int dist=0;
        while(!q.empty()){
            int size = q.size();
            if(dist == k)   break;
            for(int i=0; i<size; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !vis[current->left]){
                    q.push(current->left);
                    vis[current->left] = true;
                }
                if(current->right && !vis[current->right]){
                    q.push(current->right);
                    vis[current->right] = true;
                }
                if(parentTrack[current] && !vis[parentTrack[current]]){
                    q.push(parentTrack[current]);
                    vis[parentTrack[current]] = true;
                }
            }
            dist++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
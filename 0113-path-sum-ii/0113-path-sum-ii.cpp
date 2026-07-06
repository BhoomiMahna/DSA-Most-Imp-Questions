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
    vector<vector<int>>res;
    void find(TreeNode* root, int target,int cur,vector<int>ans){
        //if(target<0)return;
        if(!root)return;
        if(cur+root->val==target && !root->left && !root->right){
            ans.push_back(root->val);
            res.push_back(ans);
            //ans.pop_back();
            return;
        }
        else if(cur+root->val!=target && !root->left && !root->right){
            return;
        }
        ans.push_back(root->val);
        find(root->left,target,cur+root->val,ans);
        find(root->right,target,cur+root->val,ans);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ans;
        find(root,targetSum,0,ans);
        return res;
    }
};
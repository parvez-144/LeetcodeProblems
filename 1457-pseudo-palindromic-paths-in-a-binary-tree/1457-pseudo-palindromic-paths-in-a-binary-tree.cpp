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
    int f(vector<int>&output,TreeNode*root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            int oddC=0;
            output[root->val]++;
            for(int i=1;i<=9;i++){
                if(output[i]%2==1){
                    oddC++;
                }
            }
            output[root->val]--;
            if(oddC>1){
                return 0;
            }
            return 1;
        }
        int ans=0;
        output[root->val]++;
        ans+=f(output,root->left)+f(output,root->right);
        output[root->val]--;
        return ans;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>v(10,0);
        return f(v,root);
    }
};
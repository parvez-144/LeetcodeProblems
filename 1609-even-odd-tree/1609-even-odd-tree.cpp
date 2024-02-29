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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0,prev=0;
        while(!q.empty()){
            int sz=q.size();
            if(level%2){
                prev=1e9;
            }
            else{
                prev=0;
            }
            for(int i=0;i<sz;i++){
                if(level%2){
                    TreeNode* node=q.front();
                    q.pop();
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                    if(node->val%2==1||node->val>=prev){
                        return false;
                    }
                    prev=node->val;
                }
                else{
                      TreeNode* node=q.front();
                    q.pop();
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                    if(node->val%2==0||node->val<=prev){
                        return false;
                    }
                    prev=node->val;
                }
            }
            level++;
        }
        return true;
        
    }
};
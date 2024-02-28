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
int height(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        int h=height(root),count=0;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            count++;
            if(count==h){
                return q.front()->val;
            }
            for(int i=0;i<size;i++){
                TreeNode*top=q.front();
                q.pop();
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
        return 0;
    }
};
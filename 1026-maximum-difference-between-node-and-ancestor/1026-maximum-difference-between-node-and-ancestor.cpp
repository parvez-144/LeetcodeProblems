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
int solve(TreeNode* root, int mini, int maxi) {
        //if the root of the subtree is NULL return ans
        if (root == NULL) {
            return maxi-mini;
        }
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
		// Recursively calculate the max difference for left and right subtrees and take the max of them
        return max(solve(root->left, mini, maxi), solve(root->right, mini, maxi));
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }
};
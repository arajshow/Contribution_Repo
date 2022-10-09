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
    int ans;
    int helper(TreeNode *root){
        if(root == NULL) return 0;
        int l = max(helper(root->left),0);
        int r = max(helper(root->right),0);
        int val = root->val + l + r;
        ans = max(ans,val);
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        helper(root);
        return ans;
    }
};
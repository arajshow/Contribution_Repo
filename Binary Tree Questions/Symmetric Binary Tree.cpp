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
    bool help(TreeNode *s,TreeNode *e){
        if(s == NULL and e == NULL) return true;
        if(s != NULL and e == NULL) return false;
        if(s == NULL and e != NULL) return false;
        if(s->val != e->val) return false;
        
        return help(s->left,e->right) and help(s->right,e->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return help(root->left,root->right);
    }
};
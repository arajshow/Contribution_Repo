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
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        while(cur != NULL){
            if(!cur->left){
                cur = cur->right;
            }
            else{
                TreeNode *pre = cur->left;
                while(pre->right != NULL and pre->right != cur){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = cur->right;
                    cur->right = cur->left;
                    cur->left = NULL;
                    cur = cur->right;
                }
                else{
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        
    }
};
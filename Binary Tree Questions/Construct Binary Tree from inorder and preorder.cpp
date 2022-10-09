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
    int idx = 0;
    TreeNode *helper(vector<int> &p,vector<int> &in,int s,int e){
        if(s > e) return NULL;
        int val = p[idx];
        idx++;
        TreeNode *root = new TreeNode(val);
        int i;
        for(i=s;i<=e;i++){
            if(in[i] == val) break;
        }
        root->left = helper(p,in,s,i-1);
        root->right = helper(p,in,i+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx = 0;
        return helper(preorder,inorder,0,preorder.size()-1);
    }
};
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        return create(inorder,postorder,0,n-1, 0,n-1);
    }

    TreeNode* create(vector<int> &in, vector<int> &p, int is, int ie, int ps, int pe){
        if(ps > pe){
            return nullptr;
        }
        TreeNode* node = new TreeNode(p[pe]);
        int pos;
        for(int i = is; i <= ie; i++){
            if(in[i] == node->val){
                pos = i;
                break;
            }
        }
        node->left = create(in, p, is, pos - 1, ps, ps + pos - is - 1);
        node->right = create(in, p, pos + 1, ie, pe - ie + pos, pe - 1);
        return node;
    }
};
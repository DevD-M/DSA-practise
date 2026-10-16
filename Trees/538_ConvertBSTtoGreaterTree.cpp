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
    int sum=0;
    void inverseInorder(TreeNode* root){
        
        if (!root){
            return;
        }
        inverseInorder(root->right);

        sum += root->val;
        root->val = sum;

        inverseInorder(root->left);
    }
        
                
public:
    TreeNode* convertBST(TreeNode* root) {
        inverseInorder(root);
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    TreeNode* first = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder(root->left);

        if (prev != NULL && prev->val > root->val) {
            if (!first) {
                first = prev;
            }
            last = root;
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);

        int temp = first->val;
        first->val = last->val;
        last->val = temp;
    }
};

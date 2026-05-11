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
    int goodNodes(TreeNode* root) {
        int count = 0;
        countGoodNodes(root, count, INT_MIN);
        return count;
        
    }

    void countGoodNodes(TreeNode* root, int &count, int value) {
        if(!root) {
            return;
        }

        if(root->val >= value) {
            count++;
        }

        value = max(value, root->val);
        countGoodNodes(root->left, count, value);
        countGoodNodes(root->right, count, value);
    }
};
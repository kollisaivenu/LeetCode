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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>num;
        dfs(root, num);
        return num[k-1];
    }
    void dfs(TreeNode* root, vector<int>&num) {
        if(root == NULL) {
            return;
        }

        dfs(root->left, num);
        num.push_back(root->val);
        dfs(root->right, num);
    }
};
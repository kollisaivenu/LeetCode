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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        ans = max(ans, dfs(root, ans));
        return ans;
    }

    int dfs(TreeNode* root, int &ans){
        if(root == NULL){
            return 0;
        }

        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);

        ans = max(left+right+root->val, max(left+root->val, max(right+root->val, max(root->val, ans))));

        return max(left+root->val, max(right+root->val, root->val));
    }
};
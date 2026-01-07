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
    int maxProduct(TreeNode* root) {
        map<TreeNode*, long long>sumMap;
        long long totalSum = findSum(root, sumMap);
        long long ans = findMaxProduct(root, totalSum, sumMap);
        return ans%1000000007;
    }

    long long findMaxProduct(TreeNode* root, long long totalSum, map<TreeNode*, long long>&sumMap) {
        queue<TreeNode*>q;
        q.push(root);
        long long ans = LLONG_MIN;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans = max(ans, (totalSum - sumMap[node])*sumMap[node]);

            if(node->left) {
                q.push(node->left);
            }

            if(node->right) {
                q.push(node->right);
            }
        }

        return ans;
    }

    long long findSum(TreeNode* root, map<TreeNode*, long long>&sumMap) {
        if(root == NULL) {
            return 0;
        }

        sumMap[root] = root->val + findSum(root->left, sumMap) + findSum(root->right, sumMap);
        return sumMap[root];
    }
};
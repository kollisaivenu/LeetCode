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
    int sumRootToLeaf(TreeNode* root) {
        queue<pair<TreeNode*, int>>q;
        q.push(make_pair(root, root->val));
        int sum = 0;

        while(!q.empty()) {
            pair<TreeNode*, int>p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int no = p.second;

            if(!node->left && !node->right) {
                sum += no;
            }

            if(node->left) {
                q.push(make_pair(node->left, (no<<1)+node->left->val));
            }

            if(node->right) {
                q.push(make_pair(node->right, (no<<1)+node->right->val));
            }
        }

        return sum;
    }
};
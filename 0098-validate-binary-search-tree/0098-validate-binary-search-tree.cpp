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
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }

    bool validate(TreeNode* root, long minimum, long maximum) {
        if(root == NULL) {
            return true;
        }

        int ans = true;
        if(root->val > minimum && root->val < maximum) {
            ans = ans & validate(root->left, minimum, root->val);
            ans = ans & validate(root->right, root->val, maximum);
        } else {    
            return false;
        }

        return ans;
    }
};
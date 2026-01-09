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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return lcaAndMaxHeight(root).first;
    }
    pair<TreeNode*, int>lcaAndMaxHeight(TreeNode* root){
        if(!root){
            return {nullptr, 0};
        }
        pair<TreeNode*, int>leftPair = lcaAndMaxHeight(root->left);
        pair<TreeNode*, int>rightPair = lcaAndMaxHeight(root->right);

        if(leftPair.second > rightPair.second){
            return {leftPair.first, leftPair.second+1};
        }

        if(leftPair.second < rightPair.second){
            return {rightPair.first, rightPair.second+1};
        }

        return {root, leftPair.second+1};

    }
};
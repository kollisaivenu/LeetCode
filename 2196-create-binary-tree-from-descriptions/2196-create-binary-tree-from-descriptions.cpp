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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>tree;
        set<int>children;
        TreeNode* parent = nullptr;

        for(int i=0;i<descriptions.size();i++) {
            if(!tree.contains(descriptions[i][0])) {
                tree[descriptions[i][0]] = new TreeNode(descriptions[i][0]);
            }

            if(!tree.contains(descriptions[i][1])) {
                tree[descriptions[i][1]] = new TreeNode(descriptions[i][1]);
            }

            children.insert(descriptions[i][1]);
        }

        for(int i=0;i<descriptions.size();i++) {
            if(descriptions[i][2] == 0) {
                tree[descriptions[i][0]]->right = tree[descriptions[i][1]];
            } else {
                tree[descriptions[i][0]]->left = tree[descriptions[i][1]];
            }

            if(!children.contains(descriptions[i][0])) {
                parent = tree[descriptions[i][0]];
            }
        }

        return parent;
    }
};
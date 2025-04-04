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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<TreeNode*>>levels;
        unordered_map<TreeNode*, TreeNode*>parentOf;
        parentOf[root] = NULL;
        q.push(root);

        while(!q.empty()){
            q.push(NULL);
            vector<TreeNode*>level;
            while(q.front() != NULL){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);
                if(node->left){
                    parentOf[node->left] = node;
                    q.push(node->left);
                }

                if(node->right){
                    parentOf[node->right] = node;
                    q.push(node->right);
                }
            }
            q.pop();
            levels.push_back(level);
        }
        set<TreeNode*>parents;

        for(TreeNode* node: levels[levels.size()-1]){
            parents.insert(node);
        }

        while(parents.size() != 1){
            set<TreeNode*>tempSet;

            for (TreeNode* node : parents) {
                tempSet.insert(parentOf[node]);
            }
            parents = tempSet;
        }
        return *parents.begin();
    }

};
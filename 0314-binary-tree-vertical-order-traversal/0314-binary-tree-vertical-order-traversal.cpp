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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root == NULL) {
            return ans;
        }
        
        queue<pair<TreeNode*, int>>q;
        map<int, vector<int>>cols;

        q.push(make_pair(root, 0));

        while(!q.empty()) {
            pair p = q.front();
            q.pop();
            cols[p.second].push_back(p.first->val);

            if(p.first->left) {
                q.push(make_pair(p.first->left, p.second-1));
            }

            if(p.first->right) {
                q.push(make_pair(p.first->right, p.second+1));
            }

        }
        
        for(auto itr = cols.begin();itr!=cols.end();itr++) {
            vector<int>col;
            for(int j=0;j<itr->second.size();j++){
                col.push_back(itr->second[j]);
            }
            ans.push_back(col);
        }

        return ans;
    }
};
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>rsv;
        if(!root) {
            return rsv;
        }
        
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            q.push(NULL);
            int last=-1;
            while(q.front()!=NULL) {
                last = q.front()->val;
                if(q.front()->left) {
                    q.push(q.front()->left);
                }

                if(q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            q.pop();
            if(last != -1) {
                rsv.push_back(last);
            }
        }
        
        return rsv;
    }
};
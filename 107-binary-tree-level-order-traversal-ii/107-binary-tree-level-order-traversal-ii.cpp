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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;
        vector<int> level;
         
        if(root == NULL){
            return ans;       
        }
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL){
                
                //store the level in ans 
                //and clear the level
                ans.push_back(level);
                level.clear();
                
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                level.push_back(temp->val);
                
                if(temp -> left){
                    q.push(temp -> left);
                }
                
                if(temp -> right){
                    q.push(temp -> right);
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
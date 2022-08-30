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
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        
        vector<vector<int>> ans;
        
        bool left_to_right = true;
        
        queue<TreeNode *> q;
        q.push(root);
        
        //edge case
        if(root == NULL){
            return ans;   
        }
        
        while(!q.empty()){
            
            int s = q.size();
            vector<int> level(s, 0);        
            
            for(int i=0 ; i<s ; i++){
                TreeNode *temp = q.front();
                q.pop();
                
                int index = left_to_right ? i : s-i-1;
                level[index] = temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            
            ans.push_back(level);
            
            //flip left_to_right
            if(left_to_right){
                left_to_right = false;
            }else{
                left_to_right = true;
            }
            
        }
        
        return ans;
        
    }
};
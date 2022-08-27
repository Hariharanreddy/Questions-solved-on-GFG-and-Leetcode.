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
    
    pair<int, bool> check(TreeNode *root){
        
        if(root == NULL){
            return {0, true};
        }    
        
        pair<int, bool> checkLeft = check(root -> left);
        pair<int, bool> checkRight = check(root -> right);
        
        pair<int, bool> ans;
        ans.first = max(checkLeft.first, checkRight.first)+1;
        
        if(abs(checkLeft.first - checkRight.first) <= 1){
            ans.second = checkLeft.second && checkRight.second;
        }
        else{
            ans.second = false;
        }
        
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
        
        //height and check true or not
        pair<int, bool> p = check(root);
        return p.second;
        
    }
};
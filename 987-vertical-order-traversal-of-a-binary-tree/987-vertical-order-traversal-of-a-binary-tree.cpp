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
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        //mapping hd and level with elements inside them
        map< int, map<int, vector<int>> > mpp;
        vector<vector<int>> ans;
        
        //pair is having hd and level
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            
            int hd = temp.second.first;
            int level = temp.second.second;
            
            mpp[hd][level].push_back(temp.first -> val);
            
            if(temp.first -> left){
                q.push({temp.first -> left, {hd-1, level+1}});
            }
            
            if(temp.first -> right){
                q.push({temp.first -> right, {hd+1, level+1}});
            }
            
        }
    
        for(auto a : mpp)
        {
            vector<int> vec;
            for(auto b : a.second)
            {
                sort(b.second.begin(), b.second.end());
                for(auto c : b.second){
                    vec.push_back(c);
                }
            }
            
            ans.push_back(vec);
            
        }
        
        return ans;
    }
};
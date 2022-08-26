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
int getLeftHeight(TreeNode* root) {
    int height = 0;
    
    while(root){ 
        root = root->left;
        height++;
    }
    
    return height;
}

int countNodes(TreeNode* root) {
     if(root == NULL)
        return 0;
    
        int res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {

            for(int i = 0; i < q.size(); ++ i)
            {
                 ++ res;
                TreeNode *p = q.front();
                q.pop();

                if(p -> left != NULL)
                    q.push(p -> left);
                if(p -> right != NULL)
                    q.push(p -> right);
            }
        }

        return res;
}
};
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    
    //0 based indexing is followed
    
    void countNodes(struct Node* root, int &cnt)
    {
        //base case
        if(root == NULL)
        {
            return;
        }
        
        countNodes(root -> left, cnt);
        cnt++;
        countNodes(root -> right, cnt);
        
    }
    
    bool isCBT(struct Node* root, int i, int cnt)
    {
        //if leaf node
        if(root == NULL)
            return true;
            
        if(i >= cnt)
        {
            return false;
        }
        else
        {
            bool left = isCBT(root->left, 2*i+1, cnt);
            bool right = isCBT(root->right, 2*i+2, cnt);
            
            return left && right;
        }
    }
  
    bool isMaxHeap(struct Node* root)
    {
        //if leaf node
        if(root -> left == NULL && root -> right == NULL)
            return true;
        
        //if only leaf child exists
        if(root -> right == NULL)
        {
            if(root -> data > root -> left -> data)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //if both child exits
        else
        {
            bool left = isMaxHeap(root -> left);
            bool right = isMaxHeap(root -> right);
            
            bool check = root -> data > root -> left -> data
                            && root -> data > root -> right -> data;
                            
            if(left && right && check)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
    }
    
    
    
  
    bool isHeap(struct Node* root) {
        
        int totalnodes = 0;
        countNodes(root, totalnodes);
        
        if(isCBT(root, 0, totalnodes) && isMaxHeap(root))
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}  // } Driver Code Ends
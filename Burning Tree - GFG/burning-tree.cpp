// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
//User function Template for C++

class Solution {
  public:
    Node *createMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
    {
        Node *target_Node = NULL;
        
        //roots parent is NULL
        nodeToParent[root] = NULL;
        
        queue<Node *> q;
        q.push(root);
        
        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            
            //If target node
            if(temp->data == target)
            {
                target_Node = temp; 
            }
            
            //map the nodes to its parents
            if(temp -> left)
            {
                q.push(temp -> left);
                nodeToParent[temp -> left] = temp;
            }
            
            if(temp -> right)
            {
                q.push(temp -> right);
                nodeToParent[temp -> right] = temp;
            }
        }
        
        return target_Node;
        
    }
    
    int burnTheTree(Node *targetNode, map<Node *, Node *> &nodeToParent)
    {
        int time = 0;
        
        map<Node *, bool> visited;
        visited[targetNode] = true;         //target Node is alraedy visited
        
        queue<Node*> q;
        q.push(targetNode);
        
        while(!q.empty())
        {
            int size = q.size();
            int flag = 0;           //if flag is 0 it means no addition in queue has been done
            
            for(int i=0 ; i<size ;i++)
            {
                Node *temp = q.front();
                q.pop();
                
                if(temp -> left && visited[temp -> left] != true)
                {
                    flag = 1;
                    q.push(temp -> left);
                    visited[temp -> left] = true;
                }
                
                if(temp -> right && visited[temp -> right] != true)
                {
                    flag = 1;
                    q.push(temp -> right);
                    visited[temp -> right] = true;
                }
                
                if(nodeToParent[temp] && visited[nodeToParent[temp]] != true)
                {
                    flag = 1;
                    q.push(nodeToParent[temp]);
                    visited[nodeToParent[temp]] = true;
                }
            }
            
            if(flag == 1)
            {
                time++;
            }
            
        }
        
        return time;
    }
    
    
    int minTime(Node* root, int target) 
    {
        // step 1 -create Node to parent mapping and while 
        // mapping return the target node location
        map<Node *, Node *> nodeToParent;
        Node *targetNode = createMapping(root, target, nodeToParent);
        
        int ans = 0;
        ans = burnTheTree(targetNode, nodeToParent);
        
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends
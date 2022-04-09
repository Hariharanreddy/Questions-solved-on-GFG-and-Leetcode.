// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
     bool route(Node * node,int goal,vector<int> & vec){
        if(node != NULL){
            vec.push_back(node->data);
            if(node->data==goal){
                return true;
            }
            bool res1=route(node->left,goal,vec);
            if(res1){
                return true;
            }
            bool res2=route(node->right,goal,vec);
            if(res2){
                return true;
            }
            vec.pop_back();
        }
        return false;
    }
    int findDist(Node* root, int a, int b) {
        vector<int> r1;
        route(root,a,r1);
        vector<int> r2;
        route(root,b,r2);
        unordered_map<int,int> mp,mp1;
        for(auto v:r1){
            mp[v]++;
        }
        for(auto v:r2){
            mp[v]++;
        }
        for(int i=r1.size()-1;i >=0;i--){
            if(mp[r1[i]] > 1){
                mp1[r1[i]]=r1.size()-i-1;
            }
        }
        int res=INT_MAX;
        for(int i=r2.size()-1;i >=0;i--){
            if(mp[r2[i]] > 1){
                int temp=r2.size()-i-1+mp1[r2[i]];
                res=std::min(res,temp);
            }
        }
        return res;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}
  // } Driver Code Ends
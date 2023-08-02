//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> rearrangeQueue(queue<int> &q){
        
        //Solving this using queue
        queue<int> nq;
        int half_size = q.size()/2;
        
        //Storing half of the queue elements in new_queue
        for(int i = 0 ; i < half_size ; i++){
            nq.push(q.front());
            q.pop();
        }
        
        
        //Now store, elements one from stack then one from queue in vector
        vector<int> v;
        
        while(!nq.empty()){
            v.push_back(nq.front());
            nq.pop();
            
            v.push_back(q.front());
            q.pop();
        }
        
        
        return v;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
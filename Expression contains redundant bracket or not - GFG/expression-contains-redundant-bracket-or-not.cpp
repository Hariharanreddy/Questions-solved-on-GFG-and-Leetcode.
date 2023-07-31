//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        
        stack<int> st;
        int size = s.length();
        
        
        for(int i=0 ; i<size ; i++){
            
            while(i < size && s[i] != ')'){
                st.push(s[i++]);
            }    
            
            //there has to be an expression when ')' is reached
            if(st.top() != '('){   //it means there is expression
            
                bool expression_flag = false;
            
                while(st.top() != '(' ){
                    if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                        expression_flag = true;
                    }
                    st.pop();
                }
                
                if(expression_flag == false){
                    return 1;
                }
                
                st.pop();
            }
            else{
                return 1;
            }
            
            
            
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
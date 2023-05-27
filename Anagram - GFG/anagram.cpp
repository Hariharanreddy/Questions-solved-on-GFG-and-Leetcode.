//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        unordered_map<int, int> mp;
        int sizea = a.length();
        int sizeb = b.length();
        
        if(sizea != sizeb){
            return false;
        }
        
        for(int i=0 ; i<sizea ; i++){
            mp[a[i]]++;
            mp[b[i]]--;
        }
        
        for(auto it=mp.begin() ; it!=mp.end() ; it++){
            if(it -> second > 0){
                return false;
            }
        }
        
        return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends
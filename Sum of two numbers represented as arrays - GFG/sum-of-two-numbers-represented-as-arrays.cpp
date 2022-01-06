// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	vector<int> findSum(vector<int> &a, vector<int> &b)
	{
	    
        vector<int> vec;
        int carry = 0;
        
        int mini = min(a.size(), b.size())-1;
        int maxi = max(a.size(), b.size())-1; 
        
        int n = a.size()-1;
        int m = b.size()-1;
        
        while(mini >= 0)
        {
            int sum = a[n] + b[m] + carry;
            
            if(sum<=9)
            {
                vec.push_back(sum);
                carry = 0;
            }
            else
            {
                vec.push_back(sum%10);
                carry =1;
            }
            
            m--;
            n--;
            mini--;
            maxi--;
        }
        
        
        
        if(n>m)
        {
            while(maxi >= 0)
            {
                int sum = a[maxi]+carry;
                
                if(sum==10)
                {
                    vec.push_back(0);
                    carry = 1;
                }
                else
                {
                    vec.push_back(sum);
                    carry = 0;
                }
                maxi--;
                
            }
        }
        else if(m>n)
        {
            while(maxi >= 0)
            {
                int sum = b[maxi]+carry;
                
                if(sum==10)
                {
                    vec.push_back(0);
                    carry = 1;
                }
                else
                {
                    vec.push_back(sum);
                    carry = 0;
                }
                maxi--;
            }
        }
        
        if(carry == 1)
        {
            vec.push_back(1);
            reverse(vec.begin(), vec.end());
            return vec;
        }
        else
        {   
            reverse(vec.begin(), vec.end());
            return vec;
        }
        
        
        
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    
    void insertHeap(int &x) {
        if (q1.empty() || x <= q1.top())
            q1.push(x);
        else
            q2.push(x);
        balanceHeaps();
    }
    
    void balanceHeaps() {
        if (q2.size() - q1.size() == 1) {
            q1.push(q2.top());
            q2.pop();
        }
        else if (q1.size() - q2.size() == 2) {
            q2.push(q1.top());
            q1.pop();
        }
    }
    
    double getMedian() {
        if (q1.size() == q2.size())
            return (q1.top() + q2.top()) / 2.0;
        return q1.top();
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends
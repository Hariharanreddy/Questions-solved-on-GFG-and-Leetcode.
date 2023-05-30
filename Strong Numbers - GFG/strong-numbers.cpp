//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	public:
        int Factorial(int n) {
           int fact = 1;
           for (int i = 1; i <= n; i++) {
              fact = fact * i;
           }
           return fact;
        }	
        int Strong_No(int num) {
           int sum = 0;
           //Extract all the digits from num
           while (num > 0) {
              int digit = num % 10;
              sum = sum + Factorial(digit);
              num = num / 10;
           }
           return sum;
        }
        	
		int is_StrongNumber(int number)
		{
            int answer = Strong_No(number);
            if (answer == number && number != 0) {
                  return 1;
               } 
            else {
                  return 0;
               }
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_StrongNumber(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends
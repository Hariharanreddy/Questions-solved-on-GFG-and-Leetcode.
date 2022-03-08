// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void sortedInsert(stack<int> &s, int element)
{
    //when its an empty list or s.top() < num
    if(s.empty() || s.top() < element)
    {
        s.push(element);
        return;
    }
    
    //Storing and popping
    int num = s.top();
    s.pop();
    
    sortedInsert(s, element);
    
    s.push(num);
}


void SortedStack :: sort()
{
   //base case
   if(s.empty() || s.size() == 1)
   {
       return;
   }
   
   //storing and popping
   int num = s.top();
   s.pop();
   
   sort();                  //sort karke do
   
   sortedInsert(s, num);    //num ko proper jagah pe insert kardo
}
class Solution {
public:
    bool isValid(string st) {
        
        stack<char> s;
        
        int size = st.length();
        
        if(size == 1)
            return false;
        
        for(int i = 0 ; i<size ; i++)
        {
            char ch = st[i];
            if(ch == '[' || ch == '{' || ch == '(')
            {
                s.push(ch);
            }
            else
            {
                
                    if(!s.empty() && ch == ')' && s.top() == '(') 
                    {
                        s.pop();
                    }
                    else if(!s.empty() && ch == '}' && s.top() == '{')
                    {
                        s.pop();
                    }
                    else if(!s.empty() && ch == ']' && s.top() == '[')
                    {
                        s.pop();
                    }
                    else
                    {
                        s.push(ch);
                    }
            }
            
        }
        
        if(s.empty())
        {
            return true;
        }
        
        return false;
        
    }
};
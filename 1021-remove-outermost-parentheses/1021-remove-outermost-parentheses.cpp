// #include<stack>

class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string ans = "";
        stack<char> st;
        int size = s.length();
        
        
        int i = 0;
        while(i < size){
                
                string temp = "";
                st.push(s[i]);
                temp.push_back(s[i]);

                while(st.size() != 0){

                    i++;
                    if(s[i] == ')')
                    {
                        temp.push_back(s[i]);
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                        temp.push_back(s[i]);
                    }
                }
            
            i++;
            temp = temp.substr(1, temp.size() - 1);
            temp.pop_back();
            
            ans = ans + temp;
            
        }
        return ans;
    }
};
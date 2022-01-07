class Solution {
public:
    
bool isPalindrome(string s) {
    
    
        string temp;
        int size = s.size();
        int j = 0;
        for(int i = 0; i<s.size() ; i++)
        {
            if( (s[i] >= 'a' && s[i] <= 'z' )||(s[i] >= 'A' && s[i] <= 'Z' )|| (s[i] >= '0' && s[i] <= '9' ))
            {
                temp.push_back(tolower(s[i]));
                j++;
            }
        }
        
        
        int start = 0, end = j-1;
        
        if(j==-1)
        {
            return 0;
        }
    
    
        while(start<end)
        {
            if(temp[start]!=temp[end])
            {
                return false;
            }
            else
            {
                start++;
                end--;
            }
        }
        return true;
        
        
    }
};
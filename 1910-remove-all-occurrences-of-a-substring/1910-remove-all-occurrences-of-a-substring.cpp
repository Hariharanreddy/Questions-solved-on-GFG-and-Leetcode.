class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int len = part.length();
        
        while(s.size()!=0 && s.find(part) < s.length())
        {
            s.erase(s.find(part), len);
        }
        
        return s;
    }
};
class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        int len = part.length();
        
        while(s.find(part) < s.length())
        {
            s.replace(s.find(part), len, "");
        }
        
        return s;
    }
};
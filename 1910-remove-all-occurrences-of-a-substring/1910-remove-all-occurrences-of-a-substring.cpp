class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len = part.size();
        while(s.size()!=0 && s.find(part) < s.size())
        {
            s.erase(s.find(part), len);
        }
        
        return s;
    }
};
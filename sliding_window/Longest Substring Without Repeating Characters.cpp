class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    map<char, int>m;
    int i = 0, j = 0, len = 0;
    while(j < s.size()){
        if(m.find(s[j]) == m.end()){
            m[s[j]] = j;
            len = max(len, j - i + 1);
            j++;
        }
        else{
            if(i > m[s[j]]){
                m[s[j]] = j;
                len = max(len, j - i + 1);
                j++;
            }
            else{
                i = m[s[j]] + 1;
                m[s[j]] = j;
                j++;
            }
        }
    }
    return len;
    }
};
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    map<string, int> m;
    for(auto x: words) m[x]++;
    // for(auto x: m) cout << x.first << " " << x.second << endl;
    int n = words.size(), len = words[0].size();
    // cout << len << endl;
    vector<int> ans;
    string temp;
    int left = 0;
    bool flag = false;
    for(int i = 0; i < len; i++){
        temp = "";
        for(int j = i; j <= s.size() - len; j += len){
            temp = s.substr(j, len);
            // cout << temp << endl;
                if(m.find(temp) != m.end()){
                    if(flag == false){
                        left = j;
                        flag = true;
                    }
                    m[temp]--;
                    if(m[temp] == 0) m.erase(temp);
                    temp = "";
                    if(m.size() == 0){
                        ans.push_back(left);
                        flag = false;
                        for(auto x: words) m[x]++;
                    }
                }
                else{
                    flag = false;
                    temp = "";
                    m.clear();
                    for(auto x: words) m[x]++;
                }
        }
        m.clear();
        for(auto x: words) m[x]++;
    }
    return ans;
    }
};
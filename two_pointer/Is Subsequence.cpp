#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while(i < n && j < m){
        if(s[i] == t[j]){
            i++;
            j++;
        }else{
            j++;
        }
    }
    cout << (i == n ? "true" : "false") << "\n";
    return 0;
}
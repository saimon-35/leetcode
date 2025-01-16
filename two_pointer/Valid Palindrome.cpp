#include <bits/stdc++.h>
using namespace std;
char toLower(char c){
    if(c >= 'A' && c <= 'Z'){
        return c - 'A' + 'a';
    }
    return c;
}
bool isAlphanumeric(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    string t = "";
    for(int i = 0; i < n; i++){
        if(isAlphanumeric(s[i])){
            t += toLower(s[i]);
        }
    }
    n = t.size();
    if(n % 2){
        cout << "false\n";
        return 0;
    }
    for(int i = 0; i < n/2; i++){
        if(t[i] != t[n-i-1]){
            cout << "false\n";
            return 0;
        }
    }
    cout << "true\n";
    return 0;
}
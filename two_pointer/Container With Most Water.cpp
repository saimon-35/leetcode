#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> height;
    int x;
    while(cin >> x){
        height.push_back(x);
    }
    int n = height.size();
    int i = 0, j = n - 1;
    int ans = 0;
    while(i < j){
        ans = max(ans, (j - i) * min(height[i], height[j]));
        if(height[i] < height[j]){
            i++;
        }else{
            j--;
        }
    }
    cout << ans << "\n";
    return 0;
}
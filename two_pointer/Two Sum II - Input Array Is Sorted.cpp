#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int target;
    cin >> target;
    vector<int> numbers;
    int x;
    while(cin >> x){
        numbers.push_back(x);
    }
    int i = 0, j = numbers.size() - 1;
    while(i < j){
        if(numbers[i] + numbers[j] == target){
            cout << i + 1 << " " << j + 1 << "\n";
            return 0;
        }
        if(numbers[i] + numbers[j] < target){
            i++;
        }else{
            j--;
        }
    }
    return 0;
}
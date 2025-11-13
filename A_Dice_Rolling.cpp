#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int>& rolls, vector<int>& memo) {
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(memo[n] != -1) return memo[n]; 
    
    int total = 0;
    for(int i = 0; i < rolls.size(); i++) {
        total += solve(n - rolls[i], rolls, memo);
    }
    
    return memo[n] ; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    vector<int> rolls = {2,3,4,5,6,7};
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> memo(n + 1, -1);  
        cout << solve(n, rolls, memo) << endl;
    }
    
    return 0;
}
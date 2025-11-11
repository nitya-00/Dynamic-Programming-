#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
  public:
    int sol(int n, vector<int>& height, vector<int>& dp, int k) {
        if (dp[n] != -1) return dp[n];
        if(k==0)return dp[k];
        if (n == 0) return 0;
        if (n == 1) return abs(height[1] - height[0]);
        
        int c1 = sol(n - 1, height, dp, k--) + abs(height[n] - height[n - 1]);
        int c2 = sol(n - 2, height, dp, k--) + abs(height[n] - height[n - 2]);
        
        return dp[n] = min(c1, c2);
    }
    
    int minCost(vector<int>& height, int k ) {
        int n = height.size();
        if (n <= 1) return 0;
        vector<int> dp(n, -1);
        return sol(n - 1, height, dp, k);
    }
};

int main() {
    Solution sol;
    int n, k;
    cin >> n >> k;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    int result = sol.minCost(height, k);
    cout << result << endl;
    return 0;
}
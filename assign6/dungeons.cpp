#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int dpp(int row, int col, vector<vector<int>>& d,
            vector<vector<int>>dp ){
        int n = d.size();
        int m = d[0].size();
        if (row > n || col > m)
            return 0;
        if(row == n - 1 && col == m - 1) return dp[0][0];
        if(dp[row][col]!=INT_MIN)return dp[0][0];
        int p1 = INT_MIN, p2 = INT_MIN;
        if (row + 1 < n)
            p1 = dpp(row + 1, col, d, dp) + dp[row][col];
        if (col + 1 < m)
            p2 = dpp(row, col + 1, d, dp) + dp[row][col];
         int ans = max(p1,p2) ;
         dp[row][col] = min(0,ans);
        return dp[0][0];
    }
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n=d.size();
         int m = d[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1e9));
        dp[n - 1][m - 1] = min(0, d[n - 1][m - 1]);
        return dpp(n-1 , m-1 , d ,dp);
        //return abs(dp[0][0]) + 1;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dungeon(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dungeon[i][j];
        }
    }
    Solution sol;
    cout << sol.calculateMinimumHP(dungeon) << endl;
    return 0;
}
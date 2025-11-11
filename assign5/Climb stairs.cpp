#include <iostream>
using namespace std;   
class Solution {
public:
    int dfs(int i, vector<int>& cost, vector<int>& memo) {
        int n = cost.size();
        if(i >= n) return 0;

        if(memo[i] != -1) return memo[i];

        int one = dfs(i + 1, cost, memo);
        int two = dfs(i + 2, cost, memo);

        return memo[i] = cost[i] + min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);

        int startFrom0 = dfs(0, cost, memo);
        int startFrom1 = dfs(1, cost, memo);

        return min(startFrom0, startFrom1);
    }
};
int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    int result = sol.minCostClimbingStairs(cost);
    cout << result << endl;
    return 0;
}
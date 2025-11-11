#include <iostream>
#include <unordered_map>
using namespace std;

int sol(int n , vector<int>&a , int ans, vector<int>&dp, vector<bool>&vis ,
        vector<pair<int, int>> &freq) {

    if(dp[n] != -1) return dp[n];
    dp[0] = freq[0].first * freq[0].second;

    if(n == 0) return dp[n];
    if(n < 0) return 0;

    int take = sol(n-2, a, ans, dp, vis, freq) 
               + freq[n].first * freq[n].second;

    int nontake = sol(n-1, a, ans, dp, vis, freq);

    dp[n] = max(take, nontake);
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    int ans = 0;
    vector<int> a(n);
    vector<bool> vis(n, false);
    unordered_map<int,int> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    sort(a.begin(), a.end());

    
    vector<pair<int,int>> freq;
    for (auto &p : mp) {
        freq.push_back({p.first, p.second});
    }
    sort(freq.begin(), freq.end());  

    vector<int> dp(freq.size(), -1);

    cout << sol(freq.size() - 1, a, ans, dp, vis, freq) << '\n';
    return 0;
}

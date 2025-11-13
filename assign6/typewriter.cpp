#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;
class Solution {
public:
    map<char, pair<int, int>> positions;
    map<char, pair<int, int>> positions2;

    int getDistance(char from, char to) {
        if(from == 0 || to == 0) return 0;
        
        pair<int, int> pos1, pos2;
        
        if(positions.find(from) != positions.end()) {
            pos1 = positions[from];
        } else {
            pos1 = positions2[from];
        }
        
        if(positions.find(to) != positions.end()) {
            pos2 = positions[to];
        } else {
            pos2 = positions2[to];
        }
        
        return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
    }

    int dpp(int idx, char finger1, char finger2, string& s, vector<vector<vector<int>>>& dp) {
        if(idx == s.length()) return 0;
        
        int f1 = (finger1 == 0) ? 0 : finger1 - 'A' + 1;
        int f2 = (finger2 == 0) ? 0 : finger2 - 'A' + 1;
        
        if(dp[idx][f1][f2] != -1) 
            return dp[idx][f1][f2];
        
        char currentChar = s[idx];
        int cost1 = INT_MAX, cost2 = INT_MAX;
        
        cost1 = getDistance(finger1, currentChar) + dpp(idx + 1, currentChar, finger2, s, dp);
         
        cost2 = getDistance(finger2, currentChar) + dpp(idx + 1, finger1, currentChar, s, dp);
        
        return dp[idx][f1][f2] = min(cost1, cost2);
    }

    int minimumDistance(string word) {
        positions['A'] = {0, 0};
        positions['B'] = {0, 1};
        positions['C'] = {0, 2};
        positions['G'] = {1, 0};
        positions['H'] = {1, 1};
        positions['I'] = {1, 2};
        positions['M'] = {2, 0};
        positions['N'] = {2, 1};
        positions['O'] = {2, 2};
        positions['S'] = {3, 0};
        positions['T'] = {3, 1};
        positions['U'] = {3, 2};
        positions['Y'] = {4, 0};
        positions['Z'] = {4, 1};

        positions2['D'] = {0, 3};
        positions2['E'] = {0, 4};
        positions2['F'] = {0, 5};
        positions2['J'] = {1, 3};
        positions2['K'] = {1, 4};
        positions2['L'] = {1, 5};
        positions2['P'] = {2, 3};
        positions2['Q'] = {2, 4};
        positions2['R'] = {2, 5};
        positions2['V'] = {3, 3};
        positions2['W'] = {3, 4};
        positions2['X'] = {3, 5};
        vector<vector<vector<int>>> dp(word.length(), 
            vector<vector<int>>(27, vector<int>(27, -1)));
            
        return dpp(0, 0, 0, word, dp);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string word;
    cin >> word;
    
    Solution sol;
    cout << sol.minimumDistance(word) << endl;
    
    return 0;
}
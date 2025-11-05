#include <iostream>
#include<vector>
using namespace std;

    bool solve(int cur , int ans , string s) {
    if(!isdigit(s[cur]))return false;
    if(cur==s.size()-1)return true;
    if(s[cur]>=0  && s[cur]<=9)ans+=1;
    return solve(cur+1 ,ans , s);
}
int main() {
    // int n;
    // cin >> n;
    int ans=0;
    string s="";
    cin>>s;
      cout << (solve(0, ans, s) ? "true" : "false");
        //cout << '\n';
    return 0;
}

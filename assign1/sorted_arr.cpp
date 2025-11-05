#include <iostream>
#include<vector>
using namespace std;

    bool solve(int cur , int ans , vector<int> & a) {
    if(a[cur]<ans)return false;
    if(cur==a.size()-1)return true;
    if(cur>=ans)ans=a[cur];
    return solve(cur+1 ,ans , a);
}
int main() {
    int n;
    cin >> n;
    int ans=0;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
      cout << (solve(0, ans, a) ? "true" : "false");
        //cout << '\n';
    return 0;
}

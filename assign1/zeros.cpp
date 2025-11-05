#include <iostream>
#include<vector>
using namespace std;

    int solve(int cur , int ans , string a) {
    if(cur==a.size())return ans;
    if(a[cur]=='0')ans+=1;
    return solve(cur+1 ,ans , a);
}
int main() {
    int n;
    cin >> n;
    int ans=0;
    string a="";
    cin>>a;
    // vector<int> a(n);
    // for(int i=0;i<n;i++)cin>>a[i];
     cout<<solve(0 ,  ans, a);
        cout << '\n';
    return 0;
}

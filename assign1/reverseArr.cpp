#include <iostream>
#include<vector>
using namespace std;

  vector<int> solve(int cur , vector<int>& ans , vector<int> & a) {
    if(cur>0)return ans;
    //if(a[cur]>ans)ans=a[cur];
    ans.push_back(a[cur]);
    return solve(cur-1 ,ans , a);
}
int main() {
    int n;
    cin >> n;
    vector<int> ans;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    solve(n ,  ans, a);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout << '\n';
}

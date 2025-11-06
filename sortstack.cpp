#include <iostream>
#include<vector>
#include<stack>
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
    stack<int> s;
    vector<int> ans(n);
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(9);
    //for(int i=0;i<n;i++)cin>>s[i];
    solve(n ,  ans, s);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout << '\n';
}

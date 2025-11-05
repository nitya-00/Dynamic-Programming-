#include <iostream>
using namespace std;

    int solve(int n , int ans) {
    if(n==0)return ans;
    ans=solve(n/10, ans+1);
    return ans;
}
int main() {
    int n;
    cin >> n;
    int ans=0;
     cout<<solve(n, ans);
        cout << '\n';
    return 0;
}

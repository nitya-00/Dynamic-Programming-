#include <iostream>
using namespace std;

int solve(int n , int ans) {
    if(n==0 || n==1)return ans;
    ans=solve(n-1, n+ans)+solve(n-2,n+ ans);
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

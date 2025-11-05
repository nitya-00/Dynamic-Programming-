#include <iostream>
using namespace std;

int solve(int n , int ans, int k) {
    for(int i=0;i<n;i+=k){
        seen[i] = true;
        i=i+k-1;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    int ans=0;
    int k=2;
     cout<<solve(n, ans, k);
        cout << '\n';
    return 0;
}

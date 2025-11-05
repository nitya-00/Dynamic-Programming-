#include <iostream>
using namespace std;

int solve(int n) {
    if(n==0 || n==1)return n;
    int res=solve(n-1)+solve(n-2);
    return res;

}

int main() {
    int n;
    cin >> n;
     cout<<solve(n);
        cout << '\n';
    return 0;
}

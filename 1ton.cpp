#include <iostream>
using namespace std;

int solve(int n , int start) {
    if(n)return n;
    cout<<start<<" ";
    return solve(n+1,n);

}

int main() {
    int n;
    cin >> n;
     cout<<solve(n, 0);
        cout << '\n';
    return 0;
}

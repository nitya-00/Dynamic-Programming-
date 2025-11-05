#include <iostream>
using namespace std;

int solve(int n) {
    if(n==1)return 1;
    cout<<n<<" ";
    return solve(n-1);

}

int main() {
    int n;
    cin >> n;
     cout<<solve(n);
        cout << '\n';
    return 0;
}

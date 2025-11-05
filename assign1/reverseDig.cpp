#include <iostream>
using namespace std;

int reverse(int n, int res) {
    if (n == 0) return res;
    int lastDigit = n % 10;
    return reverse(n / 10, res * 10 + lastDigit);
}

int main() {
    int n;
    cin >> n;
    int rev = reverse(n, 0);
    return 0;
}
#include <iostream>
#include <stack>   
using namespace std;
class Solution {
  public:
    void deleteMid(stack<int>& s, int n, int current) {
        if (current == n) {
            return;
        }
        int top = s.top();
        s.pop();

        deleteMid(s, n, current + 1);
        
        if (current != n / 2) {
            s.push(top);
        }
    }
};
int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(9);
    s.push(4);
    s.push(3);

    deleteMid(s, 5, 0);

    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    return 0;
}

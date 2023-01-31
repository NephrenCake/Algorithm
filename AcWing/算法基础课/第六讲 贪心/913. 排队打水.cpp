#include <iostream>
#include <queue>

using namespace std;

const int N = 100010;
int n;
long long ans;
priority_queue<int, vector<int>, greater<>> heap;

int main() {
    cin >> n;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        heap.push(t);
    }

    while (!heap.empty()) {
        ans += heap.top() * (heap.size() - 1);
        heap.pop();
    }
    cout << ans;
}

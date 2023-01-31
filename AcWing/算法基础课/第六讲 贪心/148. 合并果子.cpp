#include <iostream>
#include <queue>

using namespace std;

const int N = 10010;
int n, res;
priority_queue<int, vector<int>, greater<>> heap;

int main() {
    cin >> n;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        heap.push(t);
    }

    while (!heap.empty()) {
        int c = heap.top();
        heap.pop();
        if (heap.empty()) break;
        c += heap.top();
        heap.pop();
        heap.push(c);
        res += c;
    }

    cout << res;
}

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;
int n;
PII a[N];
priority_queue<int, vector<int>, greater<>> heap;  // !×¢Òâ¶ÑµÄÓï·¨

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        int l = a[i].first, r = a[i].second;
        if (heap.empty() || l <= heap.top())
            ;
        else
            heap.pop();
        heap.push(r);
    }
    cout << heap.size();
}

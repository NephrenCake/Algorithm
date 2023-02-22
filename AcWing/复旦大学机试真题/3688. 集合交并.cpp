#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 1e5 + 10;
int n, m, t;
unordered_set<int> a, b, c, d;

int main() {
    cin >> n >> m;
    while (n-- && cin >> t)
        if (a.find(t) == a.end())
            a.insert(t), c.insert(t);
    while (m-- && cin >> t)
        if (b.find(t) == b.end()) {
            b.insert(t);
            if (c.find(t) == c.end()) c.insert(t);  // 补充并集
            if (a.find(t) != a.end()) d.insert(t);  // 补充交集
        }

    cout << d.size() << " " << c.size();
}

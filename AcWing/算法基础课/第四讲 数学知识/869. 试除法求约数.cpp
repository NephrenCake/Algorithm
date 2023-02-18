#include <iostream>
#include <set>

using namespace std;

int n, a;

set<int> get_div(int x) {
    set<int> res;
    for (int i = 1; i <= x / i; i++)
        if (x % i == i) res.insert(i);
        else if (x % i == 0) res.insert(i), res.insert(x / i);
    return res;
}

int main() {
    cin >> n;
    while (n-- && cin >> a) {
        for (auto i: get_div(a))
            cout << i << " ";
        cout << endl;
    }
}

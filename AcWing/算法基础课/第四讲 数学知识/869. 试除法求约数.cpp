#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_divisors(int a) {
    vector<int> ans;
    for (int i = 1; i <= a / i; i++) {
        if (a % i == 0) {
            ans.push_back(i);
            if (i != a / i)
                ans.push_back(a / i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        auto ans = get_divisors(a);
        for (int i: ans) cout << i << " ";
        cout << endl;
    }
}

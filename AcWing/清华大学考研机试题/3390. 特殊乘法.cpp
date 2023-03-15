#include <iostream>

using namespace std;

string a, b;
long long ans;

int main() {
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            ans += (a[i] - '0') * (b[j] - '0');
    cout << ans;
}

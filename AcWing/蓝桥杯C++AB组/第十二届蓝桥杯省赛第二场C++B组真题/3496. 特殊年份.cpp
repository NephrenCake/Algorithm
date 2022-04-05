#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// https://www.acwing.com/problem/content/3499/

int ans;
string str;

int main() {
    while (cin >> str) {
        if (str[0] == str[2] && str[3] - 1 == str[1])
            ans++;
    }
    cout << ans;
}

#include <iostream>

using namespace std;

const int N = 1010;
int n, used[N];

int main() {
    cin >> n;
    for (int i = 1, a; i <= n; i++)
        cin >> a, used[a] = 1;
    for (int i = 0; i <= n; i++)
        if (!used[i]) {
            cout << i;
            return 0;
        }
}

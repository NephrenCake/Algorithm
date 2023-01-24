#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;
int n, t;
bool a[N];

int main() {
    cin >> n;
    while (cin >> t)
        a[t] = true;

    for (int i = 1; i <= 1000; i++)
        if (a[i])
            cout << i << " ";
}

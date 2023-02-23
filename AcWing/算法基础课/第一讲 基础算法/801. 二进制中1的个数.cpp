#include <iostream>

using namespace std;

int count(int a) {
    int res = 0;
    while (a) {
        a -= (-a) & a;
        res++;
    }
    return res;
}

int main() {
    int n, a;
    cin >> n;
    while (n-- && cin >> a)
        cout << count(a) << " ";
}

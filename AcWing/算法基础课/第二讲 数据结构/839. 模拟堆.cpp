#include <iostream>

using namespace std;

string op;
int n, k, x;
const int N = 100010;
int h[N], hp[N], ph[N], cnt, tt;

void heap_swap(int i, int j) {
    swap(h[i], h[j]);
    swap(hp[i], hp[j]);
    swap(ph[hp[i]], ph[hp[j]]);
}

void down(int i) {
    int t = i;
    if (i * 2 <= tt && h[t] > h[i * 2]) t = i * 2;
    if (i * 2 + 1 <= tt && h[t] > h[i * 2 + 1]) t = i * 2 + 1;
    if (t != i) {
        heap_swap(i, t);
        down(t);
    }
}

void up(int i) {
    if (i / 2 >= 1 && h[i] < h[i / 2]) {
        heap_swap(i, i / 2);
        up(i / 2);
    }
}

int main() {
    cin >> n;
    while (n-- && cin >> op) {
        if (op == "I") {
            cin >> x;
            h[++tt] = x;
            ph[++cnt] = tt;
            hp[tt] = cnt;
            up(tt);
        } else if (op == "PM") {
            cout << h[1] << endl;
        } else if (op == "DM") {
            heap_swap(1, tt--);
            down(1);
        } else if (op == "D") {
            cin >> k;
            int t = ph[k];
            heap_swap(t, tt--);
            up(t);
            down(t);
        } else if (op == "C") {
            cin >> k >> x;
            int t = ph[k];
            h[t] = x;
            up(t);
            down(t);
        }
    }
}

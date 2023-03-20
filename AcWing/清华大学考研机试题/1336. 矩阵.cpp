#include <iostream>

using namespace std;

const int N = 110;
int n, q, op, m, a[N][N], x, y, flag;  // 标注起点坐标，是否翻转

void print() {
    if (flag == 0) {
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++)
                cout << a[i % n][j % n] << " ";
            cout << endl;
        }
    } else {
        for (int j = y; j < y + n; j++) {
            for (int i = x; i < x + n; i++)
                cout << a[i % n][j % n] << " ";
            cout << endl;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    cin >> q;
    while (q-- && cin >> op) {
        if (op == 1) {
            flag = 1 - flag;
            continue;
        }
        cin >> m;
        if (op == 2 && flag == 0 || op == 3 && flag == 1)
            x = ((x - m) % n + n) % n;
        else
            y = ((y - m) % n + n) % n;
    }
    // cout << x << " " << y << " " << flag << endl;
    print();
}

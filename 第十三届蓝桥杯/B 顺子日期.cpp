#include <bits/stdc++.h>

using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_able(int m, int d) {
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > days[m])
        return false;
    return true;
}

bool is_able2(int i, int j, int k, int l) {
    if (i == 3 && j == 4)
        return true;
    if (j == i + 1 && k == j + 1)
        return true;
    if (k == j + 1 && l == k + 1)
        return true;
    return false;
}

int main() {
    int ans = 0;
    //2022mmdd
    //2022ijkl
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 3; k++)
                for (int l = 0; l <= 9; l++) {
                    bool is = is_able(i * 10 + j, k * 10 + l) && is_able2(i, j, k, l);
                    if (is) {
                        ans++;
                    }
                    if (is_able(i * 10 + j, k * 10 + l))
                        cout << "2022" << i << j << k << l << " " << is << endl;
                }

    cout << ans << endl;
}

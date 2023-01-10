#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int k, n, a[N], f[2][N];

int main (){
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        for (int j = 1; j <= n; j++) cin >> a[j];

        int ans = 0;
        for (int l = 1; l <= n; l++) {  // a[l]为最后一个数的所有最大上升子序列的个数
            f[0][l] = 1;
            f[1][l] = 1;
            for (int m = 1; m < l; m++) {  // 遍历以a[m]为最后一个数的所有最大上升子序列的个数
                if (a[m] > a[l])
                    f[0][l] = max(f[0][l], f[0][m] + 1);  // 在所有a[m]+1中取最大值，最低为1
                else if (a[m] < a[l])
                    f[1][l] = max(f[1][l], f[1][m] + 1);  // 也可以逆向for求
            }
            ans = max(ans, max(f[0][l], f[1][l]));
        }
        cout << ans << endl;
    }
}

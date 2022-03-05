#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
int n, l, r, k;  //

vector<int> goods;  // ÉÌÆ·

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> n >> l >> r >> k;
        goods = vector<int>(n);
        for (int j = 0; j < n; ++j)
            cin >> goods[j];

        //
        int ans = 0;
        sort(goods.begin(), goods.end());
        for (int& g: goods) {
            if (g < l || g > r)
                continue;
            int nextK = k - g;
            if (nextK >= 0) {
                ans += 1;
                k = nextK;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
}

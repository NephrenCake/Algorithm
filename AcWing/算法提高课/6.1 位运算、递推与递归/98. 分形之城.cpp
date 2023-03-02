#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
#define x first
#define y second

PLL cal(int lv, LL idx) {  // lv: 等级 idx: 坐标，从0开始计数
    if (lv == 0) return {0, 0};
    // bias 坐标以方块中心个数为准 cnt 每个象限的容量 id 处于哪个象限
    LL bias = 1ll << (lv - 1), cnt = 1ll << ((lv - 1) * 2), id = idx / cnt;
    PLL p = cal(lv - 1, idx % cnt);
    if (id == 0) return {-p.y - bias, -p.x + bias};
    if (id == 1) return {p.x + bias, p.y + bias};
    if (id == 2) return {p.x + bias, p.y - bias};
    if (id == 3) return {p.y - bias, p.x - bias};
}

int main() {
    LL m, n, a, b;
    cin >> m;
    while (m-- && cin >> n >> a >> b) {
        PLL pa = cal(n, a - 1);
        PLL pb = cal(n, b - 1);
        double dx = (double) pa.x - pb.x, dy = (double) pa.y - pb.y;
        printf("%.0lf\n", sqrt(dx * dx + dy * dy) * 5);
    }
}

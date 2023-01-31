#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int n, st, ed, res;
pair<int, int> a[N];
bool succ;

int main() {
    cin >> st >> ed >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a, a + n);
    for (int i = 0; i < n;) {
        int j = i, r = -2e9;  // jΪ��ѡ���䣬r�����ұ߽�
        while (j < n && a[j].first <= st) {  // �������䲢���ܸ���Ŀ����߽�
            r = max(r, a[j].second);  // �����ұ߽�
            j++;
        }
        if (r < st) break;
        res++;
        if (r >= ed) {
            succ = true;
            break;
        }
        i = j;
        st = r;
    }
    if (!succ) res = -1;
    cout << res;
}

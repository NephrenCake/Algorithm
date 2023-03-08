#include<iostream>
#include<algorithm>

using namespace std;

const int N = 9, M = 1 << N;
int ones[M], log2[M];  // ones��¼��ͬ״̬�ж��ٸ�1��log2����1��λ��
int rows[N], cols[N], cell[3][3];  // colÿ�зֱ������Щ��  rowÿ�зֱ������Щ��  cellÿ���Ź��������Щ��
string s;

int lowbit(int x) {
    return x & -x;
}

int get_ones(int x) {
    int cnt = 0;
    while (x) cnt++, x -= lowbit(x);
    return cnt;
}

void draw(int x, int y, int t, bool set_num) {
    s[x * N + y] = set_num ? '1' + t : '.';  // tΪ0-8
    int v = set_num ? -(1 << t) : 1 << t;  // ��״̬�У�1��ʾû������0��ʾ�ѷ���
    rows[x] += v;
    cols[y] += v;
    cell[x / 3][y / 3] += v;
}

int get_state(int x, int y) {  // x��y�д���״̬���ø��ӿ�������Щ����
    return rows[x] & cols[y] & cell[x / 3][y / 3];
}

bool dfs(int cnt) {
    if (cnt == 0) return true;
    int minv = 10, x, y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (s[i * N + j] == '.') {
                int it = ones[get_state(i, j)];  // ѡ����д��ѡ�����ٵ�
                if (it < minv) {
                    minv = it;
                    x = i, y = j;
                }
            }
    for (int i = get_state(x, y); i; i -= lowbit(i)) {
        int t = log2[lowbit(i)];  //���t����Ҫ��������
        draw(x, y, t, true);  //���������
        if (dfs(cnt - 1)) return true;  //������ɹ����򷵻�
        draw(x, y, t, false);  //ʧ�������
    }
    return false;
}

int init() {
    // cnt��ʾ��ʣ���ٸ�����û����  ��ʼ״̬state��9λ������ȫ��1
    int cnt = 0;
    // ���row[0] = 111111111 �����һ�п�����9����, �����к���0-8
    for (int i = 0; i < N; i++) rows[i] = cols[i] = cell[i / 3][i % 3] = (1 << N) - 1;
    for (int i = 0, k = 0; i < N; i++)
        for (int j = 0; j < N; j++, k++)
            if (s[k] == '.') cnt++;  // ��Ҫ������
            else draw(i, j, s[k] - '1', true);
    return cnt;
}

int main() {
    for (int i = 0; i < N; i++) log2[1 << i] = i;
    for (int i = 0; i < M; i++) ones[i] = get_ones(i);
    while (cin >> s, s != "end") {
        int k = init();
        dfs(k);
        cout << s << endl;
    }
}

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double eps = 1e-6;
int n;
double a[N][N];

int gauss() {
    int x, y;  // x������ y������
    for (x = 0, y = 0; x < n; x++) {
        int t = y;  // ���ҵ���ǰ��һ�У�����ֵ����һ���������ڵ��к�
        for (int i = y; i < n; i++)
            if (fabs(a[i][x]) > fabs(a[t][x]))
                t = i;
        if (fabs(a[t][x]) < eps) continue;  // �����ǰ��һ�е����������0��������������0��������
        for (int i = x; i < n + 1; i++) swap(a[t][i], a[y][i]);  // �ѵ�ǰ��һ�У�������r��ȥ
        for (int i = n; i >= x; i--) a[y][i] /= a[y][x];  // �ѵ�ǰ�е�ͬ����һ����������Ӻ���ǰ��
        for (int i = y + 1; i < n; i++)  // �ѵ�ǰ���������������ȫ������0
            if (fabs(a[i][x]) > eps)
                for (int j = n; j >= x; j--)  // �Ӻ���ǰ����ǰ�е�ÿ�����֣�����ȥ��Ӧ�� * ���׷�0�����֣��������ܱ�֤��һ�������� a[i][0] -= 1*a[i][0];
                    a[i][j] -= a[y][j] * a[i][x];
        y++;  // ��һ�еĹ������꣬����һ��
    }
    if (y < n) {  // ˵��ʣ�·��̵ĸ�����С�� n �ģ�˵������Ψһ�⣬�ж����޽⻹��������
        for (int i = y; i < n; i++)  // ��Ϊ�Ѿ��ǽ����ͣ����� y ~ n-1 ��ֵӦ�ö�Ϊ 0
            if (fabs(a[i][n]) > eps)  // a[i][n] ���� b_i ,�� ���=0���ұ�=b_i,0 != b_i, �����޽⡣
                return 2;
        return 1;  // ���� 0 = 0������r ~ n-1�ķ��̶��Ƕ��෽��
    }
    for (int i = n - 1; i >= 0; i--)  // Ψһ�� �����������ϻش����õ����̵Ľ�
        for (int j = i + 1; j < n; j++)
            a[i][n] -= a[j][n] * a[i][j];  // ��ΪֻҪ�õ��⣬����ֻ�ö� b_i ���в������м��ֵ�����Բ��ò�������Ϊ�������
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            cin >> a[i][j];
    int t = gauss();
    if (t == 0)
        for (int i = 0; i < n; i++)
            if (fabs(a[i][n]) > eps) printf("%.2lf\n", a[i][n]);
            else printf("0.00\n");
    else if (t == 1) cout << "Infinite group solutions";
    else cout << "No solution";
}

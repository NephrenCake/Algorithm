#include <iostream>

using namespace std;

int n, m;

int main() {
    while (cin >> n >> m) {
        // ��ͼ�ҹ���
        // 1. ��n == 1 && m == 1ʱ, ��������
        // 2. ��m == 1 || n == 1ʱ,����������
        // 3. ��n��mͬʱΪ����,����������
        // 4. ��m��n��ͬʱΪ����,���� m > 1 && n > 1,��������
        if (n == 1 && m == 1) cout << "Y" << endl;
        else if (n == 1 || m == 1) cout << "N" << endl;
        else if (n % 2 == 1 && m % 2 == 1) cout << "N" << endl;
        else cout << "Y" << endl;
    }
}

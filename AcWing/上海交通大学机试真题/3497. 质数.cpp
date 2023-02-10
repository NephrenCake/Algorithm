#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N = 1e6;
int k;
vector<int> primes;
set<int> used;

void get_primes() {
    for (int i = 2; primes.size() <= 10000; i++) {
        if (used.find(i) == used.end()) primes.push_back(i);
        for (int j = 0; primes[j] < N / i; j++) {
            used.insert(primes[j] * i);
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    get_primes();
    while (cin >> k)
        cout << primes[k - 1] << endl;
}

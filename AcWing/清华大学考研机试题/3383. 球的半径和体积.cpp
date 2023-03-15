#include <iostream>
#include <cmath>

using namespace std;

double X0, Y0, Z0, X1, Y1, Z1;

int main() {
    cin >> X0 >> Y0 >> Z0 >> X1 >> Y1 >> Z1;
    double x = X1 - X0, y = Y1 - Y0, z = Z1 - Z0, r = sqrt(x * x + y * y + z * z);
    double v = (double) 4 / 3 * acos(-1) * r * r * r;
    printf("%.3f %.3f", r, v);
}

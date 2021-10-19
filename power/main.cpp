#include <iostream>

using namespace std;

double power(double x, int n)
{
    if (!n)
    {
        return 1;
    }
    if (n % 2){
        double y = power(x, (n - 1) / 2);
        return x * y * y;
    }
    double y = power(x, n / 2);
    return y * y;
}

int main() {

    cout << power(3, 3) << endl;
    return 0;
}
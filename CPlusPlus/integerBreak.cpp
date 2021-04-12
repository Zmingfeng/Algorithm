#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        else
            a = a * a % MOD;
        b = b >> 1;
    }
}

int maxNiceDivisors(int m)
{
    if (m < 3)
        return m;
    if (m % 3 == 1)
        return (LL)qmi(3, (m - 4) / 3) * 4 % MOD;
    else if (m % 3 == 2)
        return (LL)qmi(3, (m - 2) / 3) * 2 % MOD;
    else
        return (LL)qmi(3, m / 3) % MOD;
}

int main()
{
    return 0;
}
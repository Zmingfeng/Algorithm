#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int cnt = n / k;
        if (n % k != 0)
            cnt++;
        k *= cnt;
        int ans = k / n;
        if (k % n)
            ans++;
        cout << ans << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k > n)
        {
            cout << "NO" << endl;
            continue;
        }
        int a = n - k + 1;
        if (a > 0 && a % 2)
        {
            cout << "YES" << endl;
            for (int i = 0; i < k - 1; i++)
            {
                cout << 1 << ' ';
            }
            cout << a << endl;
        }
        else
        {
            int b = n - 2 * (k - 1);
            if (b > 0 && b % 2 == 0)
            {
                cout << "YES" << endl;
                for (int i = 0; i < k - 1; i++)
                {
                    cout << 2 << ' ';
                }
                cout << b << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        if (a == 1)
            cout << -1 << endl;
        else
        {
            cout << 2;
            for (int i = 1; i < a; i++)
            {
                cout << 3;
            }
            cout << endl;
        }
    }
    return 0;
}
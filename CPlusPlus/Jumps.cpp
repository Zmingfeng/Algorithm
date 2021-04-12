#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int i = 1;
        int sum = 0;
        int cnt = 0;
        while (sum < x)
        {
            sum += i;
            i++;
            cnt++;
        }
        if (x == sum || x <= sum - 2)
        {
            cout << cnt << endl;
        }
        else
        {
            cout << cnt + 1 << endl;
        }
    }
    return 0;
}
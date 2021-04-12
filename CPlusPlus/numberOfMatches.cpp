#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution
{
public:
    double getMinDistSum(vector<vector<int>> &positions)
    {
        int n = positions.size();
        double lr = 1;
        double lr_decay = 1e-3;
        double x = 0;
        double y = 0;
        double ret = 0;

        while (true)
        {
            double dx = 0;
            double dy = 0;
            double prex = x;
            double prey = y;
            for (int i = 0; i < n; i++)
            {
                int xi = positions[i][0];
                int yi = positions[i][1];
                double down = sqrt((x - xi) * (x - xi) + (y - yi) * (y - yi) + 1e-20);
                dx += x - lr * 2 * (x - xi) / down;
                dy += y - lr * 2 * (y - yi) / down;
            }
            x -= lr * dx;
            y -= lr * dy;
            lr *= (1.0 - lr_decay);

            ret = 0;
            for (int i = 0; i < n; i++)
            {
                int xi = positions[i][0];
                int yi = positions[i][1];
                ret = sqrt((x - xi) * (x - xi) + (y - yi) * (y - yi));
            }

            if (sqrt((x - prex) * (x - prex) + (y - prey) * (y - prey)) < 1e-20)
                break;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.getMinDistSum() << endl;
    return 0;
}
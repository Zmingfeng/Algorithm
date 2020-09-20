#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
class Base
{
public:
    inline virtual void who()
    {
        cout << "I am Base\n";
    }
    virtual ~Base() {}
};
class Derived : public Base
{
public:
    inline void who() // 不写inline时隐式内联
    {
        cout << "I am Derived\n";
    }
};

vector<vector<int>> transpose(vector<vector<int>> &A)
{

    vector<vector<int>> temp_vec1;
    for (int i = 0; i < A[0].size(); i++)
    {
        vector<int> temp_vec2;
        for (int j = 0; j < A.size(); j++)
        {
            temp_vec2.push_back(A[j][i]);
            cout << temp_vec2.size();
        }
        cout << endl;
        temp_vec1.push_back(temp_vec2);
    }
    return temp_vec1;
}

class Solution
{
private:
    int minimumWay(vector<vector<int>> &triangle)
    {
        int res = -1;
        int n = triangle.size();
        vector<int> memo(n + 1, -1); 
        memo[0] = triangle[0][0];
        int index = 0;

        for (int i = 1; i <= n; i++)
        {
                memo[i] = min(triangle[i][index], triangle[i][index+1]) + memo[]
        }
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        return minimumWay(triangle);
    }
};

int main()
{
    vector<vector<int>> test{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    transpose(test);
    return 0;
}
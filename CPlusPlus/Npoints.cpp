#include<iostream>
#include<vector>

using namespace std;

int main() {
    //n定为偶数
    vector<vector<int>> points = {{0, 50}, {50, 50}, {50, -50}};
    int k = 2;
    int n = points.size();
    vector<int> lines(n, 0);
    int c = 0;
    for(int i = 0; i < n; i++) {
        lines[i] = abs(points[i][0] - points[(i+1) % n][0]) + abs(points[i][1] - points[(i + 1) % n][1]);
        c += lines[i];
    }

    int splitLen = c / k;
    vector<vector<int>> ret;
    int tempSplitLen = splitLen;
    for(int i = 0; i < n; i++){
        int diff = lines[i] - tempSplitLen;
        while(diff >= 0){
            ret.push_back(points[i]);
            int next = (i + 1) % n;
            if(points[next][0] == points[i][0]) {
                if(points[next][1] > points[i][1]) {
                    ret.back()[1] = points[i][1] + tempSplitLen;
                }
                else ret.back()[1] = points[i][1] - tempSplitLen;
            }
            else {
                if(points[next][0] > points[i][0]) {
                    ret.back()[0] = points[i][0] + tempSplitLen;
                }
                else ret.back()[0] = points[i][0] - tempSplitLen;                
            }

            diff -= splitLen;
            tempSplitLen += splitLen;
        }
        tempSplitLen = abs(diff);
    }

    return 0;
}
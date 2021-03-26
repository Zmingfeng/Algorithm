#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
    vector<int> arr = {10,9,2,5,3,7,101,18};
    vector<int> temp;
    vector<int> dp;
    int maxLen = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(temp.empty() || arr[i] > temp.back()) {
            temp.push_back(arr[i]);
            dp.push_back(temp.size());
            maxLen = max((int)temp.size(), maxLen);
        }
        else {
            int left = 0, right = temp.size() - 1;
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(temp[mid] < arr[i]) left = mid+1;
                else if(temp[mid] > arr[i]) right = mid;
                else {
                    left = mid;
                    break;
                }
            }
            temp[left] = arr[i];
            dp.push_back(left + 1);
        }
    }
    for(int i = 0; i < temp.size(); i++) {
        cout << temp[i] << ' ';
    }
    cout << endl;

    return 0;
}
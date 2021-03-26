#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int partion(vector<int> &arr, int left, int right, int k) {
    if(left >= right) return left;
    int left_pos = left;
    int anchor = arr[right];
    for(int i = left; i < right; i++) {
        if(arr[i] <= anchor) swap(arr[left_pos++], arr[i]);
    }
    swap(arr[left_pos], arr[right]);
    if(left_pos == k - 1) return left_pos;
    else if(left_pos > k - 1) return partion(arr, left, left_pos - 1, k);
    else return partion(arr, left_pos+1, right, k);
}

int topK(vector<int>& arr, int k) {
    partion(arr, 0, arr.size() - 1, k);
} 


// int topK(vector<int> &arr, int k) {
//     priority_queue<int, vector<int>, greater<int>> q;
//     for(int num: arr) q.push(num);
//     for(int i = 0; i < k; i++) {
//         cout << q.top() << ' ';
//         q.pop();
//     }
// }
int main() {
    vector<int> nums = {1,3,5,7,2,4,6,8};
    int k = 4;
    topK(nums, k);
    for(int i = 0; i < k; i++){
        cout << nums[i] << ' ';
        
    }
    cout << endl;
    return 0;
}
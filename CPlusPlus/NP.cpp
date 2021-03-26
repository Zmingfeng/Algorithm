#include <iostream> 
#include <cstdio>
#include <vector>

using namespace std;


void converse(vector<int> &arr) {
   int n = arr.size();
   int left = 0;
   for(int i = 0; i < n; i++) {
       if(arr[i] < 0) swap(arr[i], arr[left++]);
   }

    int neg = 0;
    int pos = left;
    while(neg < pos && pos < n && arr[neg] < 0) {
        swap(arr[neg], arr[pos]);
        neg += 2;
        pos++;
    }
}

int main(void) {
    vector<int> arr = {   1,6,-3, -6,  9, 10,1, 2, 3 ,4, 5, -1, -7};
    converse(arr);
    for(auto num : arr) {
        cout << num << endl;
    }
    return 0;
}
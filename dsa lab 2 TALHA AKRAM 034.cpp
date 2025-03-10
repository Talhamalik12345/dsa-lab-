#include <iostream>
using namespace std;
int findMax(int arr[], int n) {
    int MaxValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > MaxValue) {
            MaxValue = arr[i];
        }
    }
    return MaxValue;
}

int main() {
    int arr[] = {12, 13,14,15,16};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Value is: " << findMax(arr, n);
    return 0;
}
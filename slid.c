#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter window size k: ";
    cin >> k;

    if (k > n) {
        cout << "Window size must be less than or equal to array size!" << endl;
        return 0;
    }

    // Step 1: Compute sum of first window
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Step 2: Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k]; // add new element, remove old
        maxSum = max(maxSum, windowSum);
    }

    cout << "Maximum sum of subarray of size " << k << " = " << maxSum << endl;

    return 0;
}

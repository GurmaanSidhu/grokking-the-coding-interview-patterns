using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class MaxSumSubArrayOfSizeK {
public:
    static int findMaxSumSubArray(int k, const vector<int>& arr) {
        int maxSum = 0;
        int wSum = 0;
        int wStart = 0;
        for (int wEnd = 0; wEnd < arr.size(); wEnd++) {
            wSum += arr[wEnd];
            if (wEnd >= k - 1) {
                maxSum = max(wSum, maxSum);
                wSum -= arr[wStart];
                wStart++;
            }
        }

        return maxSum;
    }
};

int main(int argc, char* argv[]) {
    cout << "Maximum sum of a subarray of size K: " << MaxSumSubArrayOfSizeK::findMaxSumSubArray(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;

    cout << "Maximum sum of a subarray of size K: " << MaxSumSubArrayOfSizeK::findMaxSumSubArray(2, vector<int>{2, 3, 4, 1, 5}) << endl;
}

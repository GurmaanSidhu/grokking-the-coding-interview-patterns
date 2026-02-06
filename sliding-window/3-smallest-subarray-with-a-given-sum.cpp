// Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.

using namespace std;

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

class MinSizeSubArraySum {
public:
    static int findMinSubArray(int S, const vector<int>& arr) {
        // TODO: Write your code here
        int wStart = 0, minLen = numeric_limits<int>::max(), wSum = 0; // numeric_minits -> basically find the worst case, like nothing smaller than this, around 2.2 billion or something idk
        for (int wEnd = 0; wEnd < arr.size(); wEnd++) {
            wSum += arr[wEnd];
            while (wSum >= S) {
                minLen = min(wEnd - wStart + 1, minLen);
                wSum -= arr[wStart];
                wStart++;
            }
        }
        return minLen == numeric_limits<int>::max() ? 0 : minLen; // checks if minLen is even chagned or not.
    }
};

int main(int argc, char* argv[]) {
    int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
    cout << "Smallest subarray length: " << result << endl;

    result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
    cout << "Smallest subarray length: " << result << endl;

    result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
    cout << "Smallest subarray length: " << result << endl;
}

// Longest Subarray with Ones after Replacement (hard)
// Given an array containing 0s and 1s, if you are allowed to replace no more than ‘k’ 0s with 1s, find the length of the longest contiguous subarray having all 1s.


using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class ReplacingOnes {
public:
    static int findLength(const vector<int>& arr, int k) {
        int maxLength = 0, mone = 0;
        int ws = 0;

        for (int we = 0; we < arr.size(); we++) {
            if (arr[we] == 1) {
                mone++;
            }
            if (we - ws + 1 - mone > k) {
                if (arr[ws] == 1) {
                    mone--;
                }
                ws++;
            }
            maxLength = max(maxLength, we - ws + 1);
        }
        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    cout << ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;

    cout << ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
}

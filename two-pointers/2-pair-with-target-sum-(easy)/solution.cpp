#include <iostream>
#include <vector>

using namespace std;

class PairWithTargetSum {
    public:
    static pair<int, int> search(const vector<int>&arr, int targetSum) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int total = arr[left] + arr[right];
            if (total == targetSum) {
                return make_pair(left, right);
            }
            else if (total > targetSum) {
                right--;
            }
            else {
                left++;
            }
        }
        return make_pair(-1, -1);
    }
};

int main(int argc, char *argv[]) {
    auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
    cout << "Pair with target sum: [" << result.first << "," << result.second << "]" << endl;
    result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
    cout << "Pair with target sum: [" << result.first << "," << result.second << "]" << endl;

}
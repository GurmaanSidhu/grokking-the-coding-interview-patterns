// Problem Statement
// Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.
// You can start with any tree, but once you have started you can’t skip a tree. You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.

using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class MaxFruitCountOf2Types {
public:
    static int findLength(const vector<char>& arr) {
        int maxLength = 0;
        int wStart = 0;
        unordered_map<char, int> map;
        for (int wEnd = 0; wEnd < arr.size(); wEnd++) {
            char right = arr[wEnd];
            map[right]++;

            if (map.size() > 2) {
                char left = arr[wStart];
                map[left]--;
                if (map[left] == 0) {
                    map.erase(left);
                }
                wStart++;
            }
            maxLength = max(maxLength, wEnd - wStart + 1);
        }
        // TODO: Write your code here
        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    cout << "Maximum number of fruits: "
         << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'A', 'C'})
         << endl;

    cout << "Maximum number of fruits: "
         << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'})
         << endl;
}

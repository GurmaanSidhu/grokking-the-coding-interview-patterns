//  question - Given a string, find the length of the longest substring in it with no more than K distinct characters.

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

class LongestSubstringKDistinct {
public:
    static int findLength(const string& str, int k) {
        int maxLength = 0;
        int wStart = 0;
        unordered_map<char, int> map;
        for (int wEnd = 0; wEnd < str.length(); wEnd++) {
            char right = str[wEnd];
            map[right]++;
            if ((int)map.size() > k) {
                char left = str[wStart];
                map[left]--;
                if (map[left] == 0) {
                    map.erase(left);
                }
                wStart++;
            }
            maxLength = max(maxLength, wEnd - wStart + 1);
        }
        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 2) << endl;
    cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("arsdfci", 2) << endl;
    cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("cbbebi", 3) << endl;
}

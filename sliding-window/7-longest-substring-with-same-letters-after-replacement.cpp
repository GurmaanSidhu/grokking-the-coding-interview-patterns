// Longest Substring with Same Letters after Replacement (hard)
// Problem Statement 
// Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter, find the length of the longest substring having the same letters after replacement.


using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

class CharacterReplacement {
public:
    static int findLength(const string& str, int k) {
        int ws = 0;
        int maxLength = 0, maxrepeat = 0;
        unordered_map<char, int> map;
        for (int we = 0; we < str.length(); we++) {
            char right = str[we];
            map[right]++;
            maxrepeat = max(maxrepeat, map[right]);
            if (we - ws + 1 - maxrepeat > k) {
                char left = str[ws];
                map[left]--;
                ws++;
            }
            maxLength = max(maxLength, we - ws + 1);
        }
        // TODO: Write your code here
        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    cout << CharacterReplacement::findLength("aabccbb", 2) << endl;
    cout << CharacterReplacement::findLength("abbcb", 1) << endl;
    cout << CharacterReplacement::findLength("abccde", 1) << endl;
}

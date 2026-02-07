// Problem Statement 
// Given a string, find the length of the longest substring which has no repeating characters.

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

class NoRepeatSubstring {
public:
    static int findLength(const string& str) {
        int maxLength = 0;
        int wStart = 0;
        unordered_map<char,int> map;
        // TODO: Write your code here
        for (int wEnd = 0; wEnd < str.length(); wEnd++) {
            char right = str[wEnd];
            map[right]++;
            while (map[right] > 1) {
                char left = str[wStart];
                map[left]--;
                if (map[str[wStart]] == 0) {
                    map.erase(map[str[wStart]]);
                }
                wStart++;
            }
            maxLength = max(maxLength, wEnd - wStart + 1);
        }
        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("aabccbb") << endl;
    cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abbbb") << endl;
    cout << "Length of the longest substring: "<< NoRepeatSubstring::findLength("abccde") << endl;
}

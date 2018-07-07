static const regex number_regex("\\s*(-|\\+)?(\\d+|\\d*\\.\\d+|\\d+\\.\\d*)(e(-|\\+)?\\d+)?\\s*");

class Solution {
public:
    bool isNumber(string s) {
        return regex_match(s,number_regex);
    }
};

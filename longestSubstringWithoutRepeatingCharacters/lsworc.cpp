#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // using dynamic programming to solve
        // initialize the array
        int length = s.length();
        if(length == 0){ // very base case
            return 0;
        }
        int retVal = 1;
        int* lsNum = new int[length]; // value store array
        int letters[256]; // repeatness check array, store char position
        for(int i = 0; i < 256; i++){
            letters[i] = -1;
        }

        // base case
        lsNum[0] = 1;
        letters[s[0]] = 0;
        for(int i = 1; i < s.length(); i++){
            if(letters[s[i]] == -1){ // if not repeated, add one
                lsNum[i] = lsNum[i-1] + 1;
                if(lsNum[i] > retVal){
                    retVal = lsNum[i];
                }
            }else{ // if repeated, clear previous
                int repeatPos = letters[s[i]];
                lsNum[i] = i - repeatPos;
                for(int j = repeatPos; j >= (i - lsNum[i - 1]); j--){
                    letters[s[j]] = -1;
                }
            }
            // always remeber current
            letters[s[i] - 0] = i;
        }
        
        // clear and return
        delete lsNum;
        return retVal;
    }
};


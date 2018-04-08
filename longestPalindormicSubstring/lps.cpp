#include <string>

class Solution {
	/* O(n^2) time O(1) space DP method */
public:
    string longestPalindrome(string s) {
    	// initialize all variables
		int start = 0, maxLength = 1, length = s.length();
		int len1, len2, len;
		// loop through possible centers of palidromes
		for(int i = 0; i < length; i++){
			len1 = expandPalindrome(s, length, i, i);
			len2 = expandPalindrome(s, length, i, i + 1);
			len = max(len1, len2);
			if (len > maxLength){
				start = i - (len - 1) / 2;
				maxLength = len;
			}
		}
		return s.substr(start, maxLength);
	}

private:
	// input: string, length of string, left index, and right index
	// output: max length of palindrome for the given center
	int expandPalindrome(string& s, unsigned int& sLength, int left, int right){
		int L = left, R = right;
		while(L >= 0 && R < sLength && s[i] == s[j]){
			L--;
			R++;
		}
		return R - L - 1;
	}

    	/* O(n^2) time O(n^2) space DP method
        unsigned length = s.length();
        unsigned index = 0; // return string start index
        unsigned maxLength = 0;
        bool ans[length][length];
        for(int i = length - 1; i >= 0; i--){
            for(int j = i; j < length; j++){
				if(i == j){ // one character
					ans[i][j] = true;
				}else if(j - i == 1){ // two characters
					if(s[i] == s[j]){
						ans[i][j] = true;
						if(j - i > maxLength){
							maxLength = j - i;
							index = i;
						}
					}else{
						ans[i][j] = false;
					}
				}else{ // multiple characters
					if(ans[i+1][j-1]){ // inner substring is palindromic
						if(s[i] == s[j]){
							ans[i][j] = true;
							if(j - i > maxLength){
								maxLength = j - i;
								index = i;
							}
						}else{
							ans[i][j] = false;
						} // inner substring isn't palindromic
					}else{
						ans[i][j] = false;
					}
				}
            }
        }
        return s.substring(i, ++maxLength);*/
    }
};

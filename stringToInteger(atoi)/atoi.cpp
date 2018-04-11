class Solution {
public:
    int myAtoi(string str) {
    	// final solution
	         int sign = 1, base = 0, i = 0;
        // takes care of leading white space
        while (str[i] == ' ') {
            i++;
        }
        // takes care of leading sign including "--"
        if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i++] == '-');
        }
        // add current digit
        while (str[i] >= '0' && str[i] <= '9') {
            // check if overflow
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base  = 10 * base + (str[i++] - '0');
        }
        return base * sign;

		// original solution
    	int i = 0;
    	// check white spaces
        for(i; i < str.length(); i++){
			if(str[i] != ' '){
				break;
			}
        }
        //std::cout << i << std::endl;
        // check for sign
        bool isNeg = false;
        if(str[i] == '-'){
			isNeg = true;
            i++;
		}else if(str[i] == '+'){
            i++;
        }
        // load in number
        int retVal = 0;
        int currNum = 0;
        for(i; i < str.length(); ++i){
			currNum = str[i] - '0';
            //std::cout << i << ": " << currNum << std::endl;
			if(currNum < 10 && currNum >= 0){
                if(isNeg){
                    if((INT_MIN / 10 > retVal) || ((INT_MIN / 10 == retVal) && (currNum > 8))){
                        return INT_MIN;
                    }else{
                        retVal *= 10;
                        retVal -= currNum;
                    }
                }else{
                    if((INT_MAX / 10 < retVal) || ((INT_MAX / 10 == retVal) && (currNum > 7))){
                        return INT_MAX;
                    }else{
                        retVal *= 10;
                        retVal += currNum;
                    }
                }
			}else{
                break;
            }
		}
		return retVal;
    }
};

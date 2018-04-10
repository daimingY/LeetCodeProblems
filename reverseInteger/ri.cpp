class Solution {
public:
    int reverse(int x) {
    	// store sign
        bool isNeg = false;
        if(x < 0){
            isNeg = true;
        }
        // base case
        if(x == 1 << 31){
            return 0;
        }
        x = abs(x);
        int retVal = 0;
        unsigned int counter = 1;
        // remember first digit
        int firstDigit = x % 10;
        retVal += firstDigit;
        x /= 10;
        // loop through each digit
        while(x > 0){
        	// check if exceeding boundary of integer
            if(counter == 9){
                if(firstDigit > 2){
                    return 0;
                }else if(firstDigit == 2){
                    int temp = retVal % 100000000;
                    temp *= 10;
                    temp += x % 10;
                    if(!isNeg){ // different for negative
                        if(temp > 147483648){
                            return 0;
                        }
                    }else{ // or positive
                        if(temp > 147483647){
                            return 0;
                        }
                    }
                    retVal *= 10;
                    retVal += x % 10;
                    break;
                }
            }
            // append the next digit
            retVal *= 10;
            retVal += x % 10;
            x /= 10;
            counter++;
        }
        // put sign back
        if(isNeg){
            retVal = - retVal;
        }
        return retVal;
    }
};

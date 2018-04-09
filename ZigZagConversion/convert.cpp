class Solution {
public:
    string convert(string s, int numRows) {
        string retVal = "";

        // base case
        if(s.length() <= numRows || numRows == 1){
            return s;
        }

        // index in s for diagonal lines
        unsigned int length = s.length();
        int colIndex = 0;
        numRows--;

        // append character by rows
        for(int i = 0; i <= numRows; i++){ // i represent the shift from multiples
            retVal += s[i]; // first character must exist

            colIndex = 2 * numRows - i;

            while(colIndex < length){
                // ignore the tilted line if first or last row
                if(i != 0 && i != numRows){
                    retVal += s[colIndex];
                }
                // append straight if not exceeding length
                if((colIndex + 2 * i) < length){
                    retVal += s[colIndex + 2 * i];
                }
                colIndex += 2*numRows;
            }
        }

        return retVal;
    }
};


class Solution {
public:
    vector<string> letterCombinations(unordered_map<char, vector<string>>& m,string digits) {
        if(digits.size()==1){
            return m[digits[0]];
        }
        vector<string> v = letterCombinations(m, digits.substr(1));
        vector<string> ans;
        for(auto c:m[digits[0]]){
            for(string s:v){
                ans.push_back(c+s);
            }
        }
        return ans;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return vector<string>();
        }
        unordered_map<char, vector<string>> m;
        m['2'] = vector<string>({"a","b","c"});
        m['3'] = vector<string>({"d","e","f"});
        m['4'] = vector<string>({"g","h","i"});
        m['5'] = vector<string>({"j","k","l"});
        m['6'] = vector<string>({"m","n","o"});
        m['7'] = vector<string>({"p","q","r","s"});
        m['8'] = vector<string>({"t","u","v"});
        m['9'] = vector<string>({"w","x","y","z"});
        return letterCombinations(m,digits);
    }
};

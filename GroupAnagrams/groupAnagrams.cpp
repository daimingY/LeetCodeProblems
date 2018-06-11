class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retVal; // returned 2D string matrix
        unordered_map<string, int> hash; // hash map to store string key and position in retVal
        int pos = 0, size = strs.size();
        for(int i = 0; i != size; i++){ // loop through each string
            string ans = strs[i]; // fetch current string
            sort(ans.begin(), ans.end()); // sort to get key string
            if(hash.find(ans) == hash.end()){ // if not found
                retVal.push_back(vector<string>{strs[i]}); // add new string vector
                hash[ans] = pos++; // store position in retVal for the key string
            }else{
                retVal[hash[ans]].push_back(strs[i]); // push current string into existed string vector
            }
        }
        return retVal;
    }
};

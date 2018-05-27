class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int slen =s.size();
        int wlen = words.size();
        if(slen<=0 || wlen<=0) return ans;
        int l = words[0].size();//the length of each word
        //init dic
        unordered_map<string,int> dic;
        for(auto i:words) dic[i]++;
        for(int i = 0;i<l;i++){//slide
            int left = i;
            int count=0;
            unordered_map<string,int> tmpdic;
            for(int j =i;j<=slen-l;j +=l){
                string str=s.substr(j,l);//the current word
                if(dic.count(str))//we need the current word
                {
                    tmpdic[str]++;
                    count++;
                    while(tmpdic[str]>dic[str]){//if the number of the current word is over than we need,increase left until it is exact.
                        string tmpstr=s.substr(left,l);
                        tmpdic[tmpstr]--;
                        count--;
                        left += l;
                    }
                }
                else{//if the current is worng word
                    if(slen-j < wlen*l)//consider if the remaining word is enough to cover words,this judgement can reduce the time.
                        break;
                    else{
                        count=0;
                        tmpdic.clear();
                        left = j+l;
                    }
                }
                if(count==wlen){//we find all we need.
                    ans.push_back(left);//save the ans.
                    string tmpstr=s.substr(left,l);//cut a word from the current ans,and keep finding the ans.
                    tmpdic[tmpstr]--;
                    count--;
                    left += l;
                }
            }
        }
        return ans;
    }
};

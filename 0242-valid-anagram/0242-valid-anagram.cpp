class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        unordered_map<int,int>mp;
        for(char ch:s){
            mp[ch]++;//store char and its freq
        }

        for(char ch:t){
            mp[ch]--;//remove is same char find
        }
       
        for(auto x:mp){
            if(x.second!=0){
                return false;
            }
        }
        return true;

    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            int hash[256]={0};
            for(int j=i;j<s.length();j++){
                if(hash[s[j]]==1) break;
                len=j-i+1;
                
                maxlen=max(maxlen,len);
                hash[s[j]]=1;
                
            }
        }
        return maxlen;
    }
};
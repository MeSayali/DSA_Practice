class Solution {
public:
    void reverseString(vector<char>& s) {
        string ans="";
        for(int i=s.size()-1;i>=0;--i){
            ans+=s[i];
        }
        for(int j=0;j<ans.size();j++)
        {
            s[j]=ans[j];
        }
    }
};
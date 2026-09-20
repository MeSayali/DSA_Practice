class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int reverse=26-(s[i]-'a');
            int original=i+1;

            ans+=reverse*original;
        }
        return ans;
    }
};
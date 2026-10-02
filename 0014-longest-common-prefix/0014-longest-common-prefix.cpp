class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix=strs[0];
        for(int i=0;i<strs.size();i++){
            while(strs[i].find(prefix)!=0){
                prefix.pop_back();


                if(prefix==""){
                    return "";
                }
            }
        }
        return prefix;
    }
};
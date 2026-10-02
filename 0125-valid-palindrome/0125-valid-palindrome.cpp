class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(char ch:s){
            if(isalnum(ch)){
                temp+=tolower(ch);
            }
        }

        string rev="";
        for(int i=temp.length()-1;i>=0;i--){
            rev+=temp[i];
        }

        return rev==temp;

    }
};
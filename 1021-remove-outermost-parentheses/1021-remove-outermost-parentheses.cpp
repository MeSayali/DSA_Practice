class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = ""; //final answer storing
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                if (count > 0) {
                    result += c; //Not the outermost
                }
                count++;  //Increase depth
            } else {
                count--;  //Closing bracket
                if (count > 0) {
                    result += c;  //Not the outermost )
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n = grid.size();//2
        int total = n * n;//4
        
        vector<int> freq(total + 1, 0);//(5,0) bcoz we want indexes from 0 to 4
        
        // Count every number
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                freq[grid[i][j]]++;//freq[1]=1 times
            }
        }
        
        int repeated = -1;
        int missing = -1;
        
        // Find repeated and missing
        for(int i = 1; i <= total; i++) {
            if(freq[i] == 2) {
                repeated = i;
            }
            else if(freq[i] == 0) {
                missing = i;
            }
        }
        
        return {repeated, missing};
    }
};
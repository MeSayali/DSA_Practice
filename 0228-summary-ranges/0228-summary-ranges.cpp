class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        if (nums.empty())
            return ans;

        int start = 0;

        for (int i = 1; i < nums.size(); i++) {

            // Range breaks
            if (nums[i] != nums[i - 1] + 1) {

                if (start == i - 1) {
                    ans.push_back(to_string(nums[start]));
                } 
                else {
                    ans.push_back(to_string(nums[start]) + "->" 
                                  + to_string(nums[i - 1]));
                }

                start = i;
            }
        }

        // Add the last range
        if (start == nums.size() - 1) {
            ans.push_back(to_string(nums[start]));
        } 
        else {
            ans.push_back(to_string(nums[start]) + "->" 
                          + to_string(nums.back()));
        }

        return ans;
    }
};
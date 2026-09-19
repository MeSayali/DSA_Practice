class Solution {
public:
    string triangleType(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        // First check if triangle is possible
        if(nums[0] + nums[1] <= nums[2]){
            return "none";
        }

        // All three sides equal
        if(nums[0] == nums[2]){
            return "equilateral";
        }

        // Any two sides equal
        if(nums[0] == nums[1] || nums[1] == nums[2]){
            return "isosceles";
        }

        // All sides different
        return "scalene";
    }
};
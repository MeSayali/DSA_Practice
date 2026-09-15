class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n=nums.size();
        int elesum=0;
        int digitsum=0;
        for(int i=0;i<n;i++){
            elesum+=nums[i];

            int x=nums[i];
            while(x>0){
                digitsum+=x%10;//remainder means 1
                x=x/10;
            }
        }
        return abs(elesum-digitsum);
        
    }
};
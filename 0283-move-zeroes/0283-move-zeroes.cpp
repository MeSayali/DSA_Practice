class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
           if(nums[i]!=0){
            temp.push_back(nums[i]);
           }
        }

        while(temp.size()<n){
            temp.push_back(0);
        }
        for(int j=0;j<temp.size();j++){
            nums[j]=temp[j];
        }
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int needed=target-nums[i];
            if(mp.find(needed)!=mp.end()){
                return {mp[needed],i};
            }
            mp[nums[i]]=i;//store num with their index
        }
        return {};
        
    }
};
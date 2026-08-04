class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int smallest=INT_MAX;
        int greatest=INT_MIN;
        
        unordered_set<int>st;
        for(int num:nums){
            smallest=min(smallest,num);
            greatest=max(greatest,num);
            st.insert(num);

        }

        vector<int>ans;
        for(int i=smallest+1;i<greatest;i++){ 
            if(st.find(i)==st.end()){ //means not present
                ans.push_back(i);
            }
        }
        return ans;
    }
};
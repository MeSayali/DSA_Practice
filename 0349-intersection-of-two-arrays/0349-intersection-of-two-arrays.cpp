class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;
        for(int num:nums1){
            st.insert(num);
        }
        vector<int>ans;
        for(int num:nums2){
            if(st.count(num)){
             ans.push_back(num);
             st.erase(num);
            }
            
        }
        return ans;

    }
};
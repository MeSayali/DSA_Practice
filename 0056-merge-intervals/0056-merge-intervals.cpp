class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>result;//2d to store merge intervals....
        sort(intervals.begin(),intervals.end());
        for(auto interval:intervals){
            if(result.empty() || interval[0]>result.back()[1]){//[2,6]=2 and ans=[1,3] means 3 soo 2>3 false
                result.push_back(interval);//[1,3]
            }else{
                 result.back()[1]=max(result.back()[1],interval[1]);
            }
        }
       return result;
    }
};
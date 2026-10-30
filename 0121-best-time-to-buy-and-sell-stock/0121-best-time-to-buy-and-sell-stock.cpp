class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int miniprice=prices[0]; //7
        for(int i=1;i<n;i++){
            miniprice=min(miniprice,prices[i]);
            int profit=prices[i]-miniprice;
            maxprofit=max(maxprofit,profit);
        }
        return maxprofit;

    }
};


class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1=0;//sum of all 1 to n that are not divisible by m
        int num2=0;//sum of all 1 to m that are divisible by m
        
        for(int i=1;i<=n;i++){
            if(i%m!=0){
                num1+=i;
            }
        }

        for(int j=1;j<=n;j++){
            if(j%m==0){
                num2+=j;
            }
        }
        return num1-num2;
    }
};
class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int num=n;
            int product=1;
            while(num>0){
                int digit=num%10;//243 hoga to 3 dega //it gives remainder
                product*=digit;
                num/=10;//243 ka 24 updated no. dega //it gives quotient
            }

            if(product%t==0){
                return n;
            }
            n++;
        }
    }
};
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int totalsum = 0;
        int originalN = n;

        while(n > 0){
            int rem = n % 10;
            n /= 10;
            sum += rem;
            prod *= rem;
        }
        totalsum = sum + prod;

        if( originalN % totalsum == 0) return true;
        return false;
    }
};
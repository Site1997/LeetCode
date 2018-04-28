// first enumerate palidromes, and then see if it can be the product of two n-digit numbers

class Solution {
public:
    
    long long construct_palin(int num) {
        long long ret = num;
        while (num) {
            int x = num % 10; num /= 10;
            ret = 10*ret + x;
        }
        return ret;
    }
    
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;
        long long up_bd = pow(10, n) - 1, low_bd = pow(10, n-1);
        for (int num = up_bd; num > 0; num --) {
            long long palin = construct_palin(num);
            for (long long div1 = up_bd; div1*div1 >= palin; div1 --)
                if (palin % div1 == 0)
                    return int(palin % 1337);
        }
        return 0;
    }
};

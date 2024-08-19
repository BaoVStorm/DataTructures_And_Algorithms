class Solution {
public:
    int a[1003] = {0};

    int xuly(int n) {
        if(n == 1)
            return 0;
        if(n <= 3)
            return n;

        int m = 1e6;

        for(int i = 2; i <= sqrt(n); i ++) {
            if(n % i == 0)
            {
                if(a[n / i] == 0) 
                    a[n / i] = xuly(n / i);
                m = min(m, a[n / i] + i);
                
                if(a[i] == 0) 
                    a[i] = xuly(i);
                m = min(m, a[i] + n / i);
            }
        }

        if(m == 1e6)
            return n;
        else
            return m;
    }

    int minSteps(int n) {
        return xuly(n);
    }
};
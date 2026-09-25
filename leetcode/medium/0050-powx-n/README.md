# Pow(x, n)

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Implement pow(x, n), which calculates `x` raised to the power `n` (i.e., `xn`).

 

 **Example 1:** 

```
Input: x = 2.00000, n = 10
Output: 1024.00000

```

 **Example 2:** 

```
Input: x = 2.10000, n = 3
Output: 9.26100

```

 **Example 3:** 

```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

```

 

 **Constraints:** 

- -100.0 < x < 100.0
- -231 <= n <= 231-1
- n is an integer.
- Either x is not zero or n > 0.
- -104 <= xn <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.6 MB (beats 44.15%)  
**Submitted:** 2026-09-24T20:08:37.558Z  

```cpp
class Solution {
public:
    double solve(double x, long long m){
        //base case
        if(m== 0){
            return 1;
        }
        if(m == 1){
            return x;
        }

        double half = myPow(x, m/2);

        if(m % 2 == 0){
            return half * half;
        }
        else{
            return half * half * x;
        }
    }

    double myPow(double x, int n) {
        long long m = n;
        if(m < 0){
            m = -m;
            x = 1/x;
        }
        return solve(x, m);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/powx-n/)
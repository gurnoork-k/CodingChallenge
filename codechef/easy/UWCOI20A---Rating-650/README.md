# UWCOI20A - Rating 650

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Find maximum in an Array

Given a list of $N$ integers, representing height of mountains. Find the height of the tallest mountain.

### Input:
- First line will contain $T$, number of testcases. Then the testcases follow.
- The first line in each testcase contains one integer, $N$.
- The following line contains $N$ space separated integers: the height of each mountains.
### Output:

For each testcase, output one line with one integer: the height of the tallest mountain for that test case.

### Constraints
- $1 \leq T \leq 10$
- $1 \leq N \leq 100000$
- $0 \leq$ height of each mountain $\leq 10^9$
### Sample 1:
Input
Output

```
1
5
4 7 6 3 1
```

```
7
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-16T17:59:13.267Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> arr(N);
        for(int i=0; i< N; i++){
            cin >> arr[i];
        }
        
        int maxn = INT_MIN;
    	for(int i=0; i< N; i++){
    	    if(arr[i] > maxn){
    	        maxn = arr[i];
	    }
	}
	cout << maxn << endl;
    }
	
	return 0;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/UWCOI20A)
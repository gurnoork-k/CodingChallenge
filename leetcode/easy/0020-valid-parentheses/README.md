# Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

 

 **Example 1:** 

 **Input:**  s = "()"

 **Output:**  true

 **Example 2:** 

 **Input:**  s = "()[]{}"

 **Output:**  true

 **Example 3:** 

 **Input:**  s = "(]"

 **Output:**  false

 **Example 4:** 

 **Input:**  s = "([])"

 **Output:**  true

 **Example 5:** 

 **Input:**  s = "([)]"

 **Output:**  false

 

 **Constraints:** 

- 1 <= s.length <= 104
- s consists of parentheses only '()[]{}'.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.8 MB (beats 67.25%)  
**Submitted:** 2026-09-16T16:32:21.869Z  

```cpp
class Solution {
private:
    bool matches(char ch, char top){
        if(top == '(' && ch == ')') return true;
        else if(top == '[' && ch == ']') return true;
        else if(top == '{' && ch == '}') return true;
        else return false;
    }

public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i< s.length(); i++){
            char ch = s[i];
            //if opening bracket
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            //if closing bracket
            else{
                if(!st.empty()){
                    char top = st.top();
                    if(matches(ch, top)){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{return false;}
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-parentheses/)
# Add Two Numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two  **non-empty**  linked lists representing two non-negative integers. The digits are stored in  **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

 **Example 1:** 

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

```

 **Example 2:** 

```
Input: l1 = [0], l2 = [0]
Output: [0]

```

 **Example 3:** 

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

```

 

 **Constraints:** 

- The number of nodes in each linked list is in the range [1, 100].
- 0 <= Node.val <= 9
- It is guaranteed that the list represents a number that does not have leading zeros.

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 38.90%)  
**Memory:** 77.2 MB (beats 45.94%)  
**Submitted:** 2026-09-16T16:30:51.229Z  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void insertAtTail(ListNode* &sumHead, ListNode* &sumTail, int digit){
        ListNode* temp = new ListNode(digit);
        if(sumHead == NULL){
            sumHead = temp;
            sumTail = temp;
            return;
        }
        sumTail -> next = temp;
        sumTail = temp;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumHead = NULL;
        ListNode* sumTail = NULL;
        int carry = 0;

        while(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2->val + carry;
            int digit = sum % 10;
            insertAtTail(sumHead, sumTail, digit);
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = l1->val + carry;
            int digit = sum % 10;
            insertAtTail(sumHead, sumTail, digit);
            carry = sum / 10;
            l1 = l1->next;      
        }
        while(l2 != NULL){
            int sum = l2->val + carry;
            int digit = sum % 10;
            insertAtTail(sumHead, sumTail, digit);
            carry = sum / 10;
            l2 = l2->next;      
        }
        while(carry != 0){
            int digit = carry % 10;
            insertAtTail(sumHead, sumTail, digit);
            carry = carry / 10;
        }
        return sumHead;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/add-two-numbers/)
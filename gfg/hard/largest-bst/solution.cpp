/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class info{
    public:
        int maxi;
        int mini;
        bool isBst;
        int size;
};

info solve(Node* root, int &ans){
    //base case
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max({root->data, left.maxi, right.maxi});
    currNode.mini = min({root->data, left.mini, right.mini});

    if(left.isBst && right.isBst && 
       (root->data > left.maxi && root->data < right.mini)){
        currNode.isBst = true;
    }
    else{
        currNode.isBst = false;
    }

    if(currNode.isBst){
        ans = max(ans, currNode.size);
    }
    return currNode;
}

class Solution {
  public:

    int largestBst(Node *root) {
        int maxSize = 0;
        info temp = solve(root, maxSize);
        return maxSize;
    }
};
/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    void inorder(Node* root, vector<int> &in){
        if(root == NULL){
            return;
        }
    
        inorder(root-> left, in);
        in.push_back(root-> data);
        inorder(root-> right, in);
    }
    
    vector<int> mergeArrays(vector<int> a, vector<int> b){
        vector<int> ans(a.size() + b.size());
        int i = 0, j =0;
        int k = 0;
        
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                ans[k++] = a[i];
                i++;
            }
            else{
                ans[k++] = b[j];
                j++;
            }
        }
        
        while(i < a.size()){
            ans[k++] = a[i];
            i++;
        }
        
        while(j < b.size()){
            ans[k++] = b[j];
            j++;
        }
        return ans;
    }
    
    // Node* inorderToBst(int s, int e, vector<int> &in){
    //     //base case
    //     if(s> e){
    //         return NULL;
    //     }
    //     int mid = (s+e) / 2;
    //     root-> left = inorderToBst(s, mid-1, in);
    //     root-> right - inorderToBst(mid+1, e, in);
    //     return root; 
    // }
        
    vector<int> merge(Node *r1, Node *r2) {
        // code here
        vector<int> bst1, bst2;
        
        
        inorder(r1, bst1);
        inorder(r2, bst2);
        
        vector<int> mergedArr = mergeArrays(bst1, bst2);
        return mergedArr;
        
        // int s = 0; 
        // int e = mergedArr.size()-1;
        // Node* ans = inorderToBst(s, e, mergedArr);
        // return ans;
    }
};
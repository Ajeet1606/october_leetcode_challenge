<<<<<<<<<<--------------------Hash Set Solution------------------>>>>>>>>>>>>>>>>
O(n) & O(n)


class Solution {
public:
    unordered_set<int>s;
    bool findTarget(TreeNode* root, int k) {
        if(k == 0) return true;
        if(root == NULL) return false;
        int cur = root->val;
        if(s.find(k - cur) != s.end()) return true;
        s.insert(cur);
        return findTarget(root->left, k) or findTarget(root->right, k);
    }
};


<<<<<<<<<<-------------Array + 2 pointer------------------->>>>>>>>>>>>>>>>>>>>>>>
O(n) & O(n)


class Solution {
public:
    
    void inorder(TreeNode* root, int k, vector<int>&arr){
        if(!root) return;
        inorder(root->left, k, arr);
        arr.push_back(root->val);
        inorder(root->right, k, arr);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root, k, arr);
        int i=0, j = arr.size()-1;
        while(i<j){
            int sum = arr[i]+arr[j];
            if(sum == k) return true;
            sum > k ? j--: i++;
        }
        return false;
    }
};
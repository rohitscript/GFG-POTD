// Union of Two Sorted Arrays with Distinct Elements
// Given two sorted arrays a[] and b[], where each array contains distinct elements , the task is to return the elements in the union of the two arrays in sorted order.

// Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
// Examples:

// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
// Output: 1 2 3 4 5 6 7
// Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
   vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> res;
        set<int> s;
        int i=0, j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                s.insert(a[i++]);
            }
            else{
                s.insert(b[j++]);
            }
        }
        while(i<a.size()){
            s.insert(a[i++]);
        }
        while(j<b.size()){
            s.insert(b[j++]);
        }
        for(int x:s){
            res.push_back(x);
        }
        return res;
    }
};

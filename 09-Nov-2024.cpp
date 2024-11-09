//Minimum sum
//Given an array arr[] such that each element is in the range [0 - 9], find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. Return a string without leading zeroes.

///////Examples :

//Input: arr[] = [6, 8, 4, 5, 2, 3]
//Output: 604
//Explanation: The minimum sum is formed by numbers 358 and 246.

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
     string num1="";
        string num2="";
        bool once=false;
        bool n1=true;
        bool n2=true;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(once){
                if(arr[i]!=0){
                    n1=false;
                }
                if(!n1){
                num1+=to_string(arr[i]);
                }
                once=false;
            }
            else{
                if(arr[i]!=0){
                    n2=false;
                }
                if(!n2){
                num2+=to_string(arr[i]);
                }
                once=true;
            }
        }
        int i=num1.size()-1,j=num2.size()-1;
        int c=0;
        string ans="";
        while(i>=0 && j>=0){
            int x=(num1[i]-'0');
            int y=(num2[j]-'0');
            int val=x+y+c;
            if(val>=10){
                c=val/10;
                val=val%10;
            }
            else{
                c=0;
            }
            i--;
            j--;
            ans+=to_string(val);
        }
        
    while(i>=0){
        int x=(num1[i]-'0');
        int val=x+c;
        if(val>=10){
            c=val/10;
            val=val%10;
        }
        else{
            c=0;
        }
        i--;
        ans+=to_string(val);
    }
    while(j>=0){
        int x=(num2[j]-'0');
        int val=x+c;
        if(val>=10){
            c=val/10;
            val=val%10;
        }
        else{
            c=0;
        }
        j--;
        ans+=to_string(val);
    }
    if(c!=0)
    ans+=to_string(c);
    reverse(ans.begin(),ans.end());
    return ans;
    }};

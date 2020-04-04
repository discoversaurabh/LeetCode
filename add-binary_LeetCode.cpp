#include<vector>
class Solution 
{
public:
    string addBinary(string a, string b) {
        string ans="";
        int len1 = a.length();
        int len2 = b.length();
        int carry = 0;
        int i=len1-1, j=len2-1;
        char sum;
        
        while(i>=0 || j>=0)
        {
            sum = 0;
            
            if(i >= 0)
                carry += a[i]-'0';
            if(j >= 0)
                carry += b[j]-'0';
            
            if (carry == 1 || carry == 3)
                sum = '1';
            else if(carry == 0 || carry == 2)
                sum = '0';
            
            if (carry == 0 || carry == 1)
                carry = 0;
            else if(carry == 3 || carry == 2)
                carry = 1;
            
            ans = sum + ans;
                
            i--;
            j--;
        }
        
        if(carry)
            ans = '1' + ans;
        
        return ans;
    }
}; 

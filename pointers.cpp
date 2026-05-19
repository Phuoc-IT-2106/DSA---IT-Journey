#include <iostream>
#include <vector>
#include <string>
using namespace std;
//FIND 2 NUMBERS THAT TOTAL = TARGET (SORTED ARRAY)
class Solution{
    public:
    void print(vector<int>&result){
         for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
    }
    vector<int>twosum(vector<int>&a, int target){
        int left = 0;
        int right = a.size() - 1;
        while(left < right){
            int sum = a[left] + a[right];
            if(sum == target){
                return {left + 1, right + 1};
            }
            else if(sum < target){
                left++;
            }
            else right--;
        }
    
    return {};
    }

    //CHECK IF A STRING IS PALINDROME
    bool IsPalindrome(string s){
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right --;
            if(tolower(s[left]) != tolower(s[right])) return false;
            left ++;
            right--;
        }
    
    return true;
}

//REVERSE STRING
    string ReverseString(string s){
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            char temp;
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        return s;
    }

//MOVE THE NUMBER '0' TO THE RIGHTMOST OF VECTOR
vector<int>MoveZero(vector<int>&a){
    int left = 0;
    for(int right = 0; right < a.size(); right++){
        if(a[right] != 0) {
            swap(a[left], a[right]);
            left++;
        }
    }
    return a;
}

//REMOVE DUPLICATES FROM THE ARRAY(SORTED ARRAY)

vector<int>RemoveDuplicates(vector<int>&a){
    int left = 1;
    for(int right = 1; right < a.size(); right++){
        if(a[right] != a[right - 1]){
            a[left] = a[right];
            left++;
        }
    }
    vector<int>result(left);
    for(int i = 0; i < left; i++){
        result[i] = a[i];
    }
    return result;
}
};







int main()
{
    Solution sol;
    vector<int>arr1 = {1,2,3,4,5,6,7};
    int target = 10;
    vector<int>result1 = sol.twosum(arr1,target);
    //sol.print(result);
    //cout << sol.IsPalindrome("hello");
    //cout << sol.ReverseString("hello");
    vector<int>arr2 = {0,2,0,4,0,6,7};
    vector<int>result2 = sol.MoveZero(arr2);
    //sol.print(result2);
    vector<int>result3 = sol.RemoveDuplicates(arr2);
    sol.print(result3);
    return 0;
    
}
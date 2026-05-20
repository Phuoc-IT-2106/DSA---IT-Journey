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

//REMOVE ELEMENT - https://leetcode.com/problems/remove-element/description/?envType=problem-list-v2&envId=two-pointers
int RemoveElement(vector<int>&a, int val){
    int left = 0;
    for(int right = 0; right < a.size(); right++){
        if(a[right] != val) {
            a[left] = a[right];
            left++;
        }
    }
    return left;
}

//SQUARE OF A SORTED ARRAY - https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=problem-list-v2&envId=two-pointers
vector<int>Square_SortedArray(vector<int>&a){
    vector<int>result(a.size());
    int index = a.size()- 1;
    int left = 0;
    int right = a.size()-1;
    while(left <= right){
        if(abs(a[left]) > abs(a[right])){
             result[index]   = a[left] * a[left];
             left++;
        }
        else {
             result[index]   = a[right] * a[right];
             right--;
        }
        index--;
        }
    return result;
}

//REVERSE VOWEL OF A STRING - https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=problem-list-v2&envId=two-pointers
bool CheckVowel(char a){
    return (a == 'a') || (a == 'e') || (a == 'u') || (a == 'i') || (a == 'o') ;
}
string ReverseVowels(string s){
    int left = 0;
    int right = s.size() - 1;
    while(left < right){
    while(left < right && !CheckVowel(s[left])) left++;
    while(left < right && !CheckVowel(s[right])) right--;
    if(left < right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
    }
    return s;
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
    vector<int>arr2 = {0,0,0,2,4,6,7};
    //vector<int>result2 = sol.MoveZero(arr2);
    //sol.print(result2);
    vector<int>result3 = sol.RemoveDuplicates(arr2);
    //sol.print(result3);
   // cout << sol.RemoveElement(arr2,0);
    vector<int>result4 = sol.Square_SortedArray(result3);
    //sol.print(result4);
    cout << sol.ReverseVowels("hello");
    return 0;
    
}
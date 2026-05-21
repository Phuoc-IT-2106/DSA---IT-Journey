#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
class Solution{
    public:
  void print(vector<int>&a){
      for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
  }
   void print_string(vector<char>&a){
      for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
  }
  vector<int>TwoSum(vector<int>&a, int target){
      int n = a.size();
      int left = 0;
      int right = n - 1;
      while(left < right){
          int sum = a[left] + a[right];
          if(sum == target) return {left + 1, right + 1};
          else if (sum < target) left++;
          else right --;
      }
      return {};
  }
  bool validPalindrome(string s){
      int n = s.length();
      int left = 0;
      int right = n - 1;
      while(left < right){
          while(left < right && !isalnum(s[left])) left++;
          while(left < right && !isalnum(s[right])) right--;
          if(tolower(s[left]) != tolower(s[right])) return false;
          left++;
          right--;
      }
      return true;
  }    
  vector<char>ReverseString(vector<char>&a){
    int n = a.size();
    int left = 0;
    int right = n - 1;
    while(left < right){
        swap(a[left], a[right]);
        left++;
        right--;
    }
    return a;
  }

  vector<int>MoveZeroes(vector<int>&a){
    int n = a.size();
    int left = 0;
    vector<int> temp(n);
    for(int right = 0; right < n; right ++){
        if(a[right] != 0){
            swap(a[left], a[right]);
            left++;
        }
    }
    for(int i = 0; i < n; i++){
        temp[i] = a[i];
    }
    return temp;
  }  

  vector<int>RemoveDuplicates(vector<int>& a){
    int n = a.size();
    int left = 1;
    for(int right = 1; right < n; right ++){
        if(a[right] != a[right - 1]){
            a[left] = a[right];
            left++;
        }    
    }
    vector<int>temp(left);
    for(int i = 0; i < left ; i++){
        temp[i] = a[i];
    }
    return temp;
  }

  vector<int>RemoveElements(vector<int>&a, int target){
    int n = a.size();
    int left = 0;
    for(int right = 0; right < n; right++){
        if(a[right] != target){
            a[left] = a[right];
            left++;
        }
    }
    vector<int>temp(left);
    for(int i = 0; i < left; i++){
        temp[i] = a[i];
    }
    return temp;
  }

  vector<int>SquaresOfSortedArray(vector<int>&a){
    int n = a.size();
    int left = 0;
    int right = n - 1;
    vector<int> b(n);
    int index = n - 1;
    int square = 0;
    while(left <= right){
        if(abs(a[left]) > abs(a[right])){
            square = a[left] * a[left];
            b[index] = square;
            left++;
        }
        else{
            square = a[right] * a[right];
            b[index] = square;
            right--;
        }
        
        index--;
    }
    return b;
  }

  bool isVowels(char s){
    char k = tolower(s);
    return (k == 'u') || (k == 'e') || (k =='o') || (k =='a') || (k == 'i');
  }

  string ReverseVowels(string s){
    int left = 0;
    int n = s.length();
    int right = n - 1;
    while(left < right){
        while(left < right && !isVowels(s[left])) left++;
        while(left < right && !isVowels(s[right]))right--;
        if(left < right){
            swap(s[left], s[right]);
        }
         left++;
         right--;
    }
    return s;
  }

  string ReverseStringII(string s, int k ){ 
    int n = s.length();
    for(int i = 0; i < n; i += 2*k){
        int left = i;
        int right = min(i + k - 1, n - 1);
        while(left < right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    return s;

  }

  vector<vector<int>>ThreeSum(vector<int>&a){
    vector<vector<int>> result;
    sort(a.begin(), a.end());
    int n = a.size();
    for(int i = 0; i < n - 2; i++){
        if(i > 0 && a[i] == a[i - 1]) continue;
        int target = -a[i];
       int left = i + 1;
       int right = n - 1;
        while(left < right){
        int sum = a[left] + a[right];
        if(sum == target){
            result.push_back({a[i], a[left], a[right]});
            while(left < right && a[left] == a[left + 1])left++;
            while(left < right && a[right] == a[right - 1]) right--;
            left++;
            right--;
        }
        else if(sum < target) left++;
        else right --;
    }}  
  
  return result;
}
//PRINT FUNCTION
void printResult(vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]";
}
};

int main(){
  Solution sol;
  vector<int> arr = {1,2,3,4,5,6,7};
  //vector<int> result = sol.TwoSum(arr,12);
  //sol.print(result);
  //cout << sol.validPalindrome("A man, a plan, a canal: Panama");
  //vector<char> s = {'H','e','l','l','o'};
  //vector<char>result = sol.ReverseString(s);
  //sol.print_string(result);
  vector<int> arr2 = {-1,3,4,9,12};
  //vector<int> result2 = sol.MoveZeroes(arr2);
  //vector<int> result2 = sol.RemoveDuplicates(arr2);
  //vector<int> result3 = sol.RemoveElements(arr2,0);
 // vector<int> result3 = sol.SquaresOfSortedArray(arr2);
  //sol.print(result3);
  //cout << sol.ReverseVowels("leetcode");
  //cout << sol.ReverseStringII("abcd",2);
  vector<int> arr3 = {-1,0,1,2,-1,-4};
  vector<vector<int>> threesum_result = sol.ThreeSum(arr3);
  sol.printResult(threesum_result);
  return 0;
    
    
}
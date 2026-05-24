#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
class Solution{
    public:
    //FIRST UNIQUE CHAR IN A STRING - https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=problem-list-v2&envId=string
    int FirstUnique(string s){
        int n = s.length();
        int count[26] = {0};
        for(char c: s){
            count[c - 'a']++;
        }
        for(int i = 0; i < n; i++){
            if(count[s[i] - 'a'] == 1) return i;
        }
        return -1;
        }

        //VALID ANAGRAM - https://leetcode.com/problems/valid-anagram/?envType=problem-list-v2&envId=string
        bool ValidAnagram(string s, string t){
            int count[26] = {0};
            for(char c: s){
                count[c - 'a']++;
            }
            for(char c: t){
                count[c - 'a']--;
            }
            for(int i = 0; i < 26; i++){
                if(count[i] != 0) return false;
            }
            return true;
        }

        //FIND THE DIFFERENCE - https://leetcode.com/problems/find-the-difference/?envType=problem-list-v2&envId=string
        char FindTheDifference(string s, string t){
            char result = 0;
            for(char c: s){
                result ^= c;
            }
            for(char c: t){
                result ^= c;
            }
            return result;
        }

        //JEWELS AND STONES - https://leetcode.com/problems/jewels-and-stones/?envType=problem-list-v2&envId=string
        int Jewels_Stones(string j, string s){
            bool isJewels[256] = {false};
            for(char c: j){
                isJewels[c] = true;
            }
            int count = 0;
            for(char c: s){
                if(isJewels[c]){
                    count++;
                }
            }
            return count;
        }

        //CHECK PANGRAM - https://leetcode.com/problems/check-if-the-sentence-is-pangram/?envType=problem-list-v2&envId=string
        bool CheckPangram(string s){
            bool seen[26] = {false};
            for(char c: s){
                seen[c - 'a'] = true;
            }
            for(int i = 0; i < 26; i++){
                if(!seen[i]) return false;
            }
            return  true;
        }

        //FIND THE INDEX OF THE FIRST OCCURENCE - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=problem-list-v2&envId=string
        int FirstOccurence(string haystack, string needle){
            int n = haystack.length();
            int m = needle.length();
            if(m == 0) return 0;
            if(m > n) return -1;
            for(int i = 0; i <= n - m; i++){
                bool found = true; //assuming that haystack contains needle for each window
                for(int j = 0; j < m; j++){
                if(haystack[i + j] != needle[j]){
                    found = false;
                    break;
                }
            }
                if(found) return i;
        }
        return -1;
    }
    
    //Length Of Last Word - https://leetcode.com/problems/length-of-last-word/description/
    int LengthOfLastWord(string s){
        int n = s.size();
        int i = n - 1;
        int length = 0;
        while(i > 0 && s[i] == ' ') i--;
        while(i > 0 && s[i] != ' '){
            length++;
            i--;
        }
        return length;
    }

    //Reverse Words - https://leetcode.com/problems/length-of-last-word/description/
    string ReverseWords(string s){
        stringstream ss(s);
        vector<string> words;
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        reverse(words.begin(),words.end());
        string result = "";
        for(int i = 0; i < words.size(); i++){
            if(i > 0) result += " ";
            result += words[i];
        }
        return result;
    }

    //Sort Sentence - https://leetcode.com/problems/sorting-the-sentence/description/
    string SortSentence(string s){
        stringstream ss(s);
        vector<string> words(10);
        string word;
        while(ss >> word){
            int pos = word.back() - '0';
            string actualword = word.substr(0,word.length() - 1); //Substract from the beginning to the prev of last char
            words[pos] = actualword;
        }
        string result = "";
        for(int i = 1; i <= 9; i++){
            if(!words[i].empty()){
                if(!result.empty()){
                    result += " ";
                }
                result += words[i];
            }
        }
        return result;
    }
    };

int main(){
    Solution sol;
   // cout << sol.FirstUnique("loveleetcode") << endl;
    //cout << sol.ValidAnagram("anagram","nagaram") << endl;
    //cout << sol.ValidAnagram("rat","car") << endl;
    //cout << sol.FindTheDifference("ae","aea");
    //cout << sol.Jewels_Stones("aA", "aAAbbbb") << endl;
    //cout << sol.CheckPangram("thequickbrownfoxjumpsoverthelazydog");
    //cout << sol.CheckPangram("leetcode");
    //cout << sol.FirstOccurence("leetcode","leeto") << endl;
    //cout << sol.LengthOfLastWord("   fly me   to   the moon  ");
    //cout << sol.ReverseWords("   fly me   to   the moon  ");
    cout << sol.SortSentence("is2 sentence4 This1 a3") << endl;
}
/*******************************************************************
* https://leetcode.com/problems/find-the-difference/
* Easy
* 
* Conception: 
*  1. 
*
* You are given two strings s and t.
* String t is generated by random shuffling string s and then add one more letter at a random position.
* Return the letter that was added to t.
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1.
*
*******************************************************************/
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;

        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }

        for(int i=0;i<t.length();i++){
            if(!mp.count(t[i])) return t[i];
            if(mp.count(t[i]) and mp[t[i]]==0){
                return t[i];
            }
            mp[t[i]]--;
        }
        return ' ';
    }
};
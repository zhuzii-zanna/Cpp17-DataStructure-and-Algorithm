/*******************************************************************
* https://leetcode.com/problems/expressive-words/
* Medium
* 
* Conception: 
*  1. 
*
* Sometimes people repeat letters to represent extra feeling,
* such as "hello" -> "heeellooo", "hi" -> "hiiii".  In these strings like "heeellooo",
* we have groups of adjacent letters that are all the same:  "h", "eee", "ll", "ooo".
*
* For some given string S, a query word is stretchy
* if it can be made to be equal to S by any number of applications of the following extension operation:
* choose a group consisting of characters c, and add some number of characters c to the group
* so that the size of the group is 3 or more.
*
* For example, starting with "hello", we could do an extension on the group "o" to get "hellooo",
* but we cannot get "helloo" since the group "oo" has size less than 3.
* Also, we could do another extension like "ll" -> "lllll" to get "helllllooo". 
* If S = "helllllooo", then the query word "hello" would be stretchy
* because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = S.
*
* Given a list of query words, return the number of words that are stretchy. 
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
/*
In check function, use two pointer:

    If S[i] == W[j, i++, j++
    If S[i - 2] == S[i - 1] == S[i] or S[i - 1] == S[i] == S[i + 1], i++
    return false
*/

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for (auto &W : words){
            if (check(S, W)){
                res++;
            }
        }
        return res;
    }

    bool check(string S, string W) {
        int n = S.size(), m = W.size(), j = 0;
        for (int i = 0; i < n; i++){
            if (j < m && S[i] == W[j]){
                j++;
            }else if (i > 1 && S[i - 2] == S[i - 1] && S[i - 1] == S[i]){
                //
            }else if (0 < i && i < n - 1 && S[i - 1] == S[i] && S[i] == S[i + 1]){
                //
            }else{
                return false;
            }
        }
        return j == m;
    }
};

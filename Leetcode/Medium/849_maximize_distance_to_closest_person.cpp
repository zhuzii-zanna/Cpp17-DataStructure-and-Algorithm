/*******************************************************************
* https://leetcode.com/problems/maximize-distance-to-closest-person/
* Medium
* 
* Conception: 
*  1. 
*
* You are given an array representing a row of seats
* where seats[i] = 1 represents a person sitting in the ith seat,
* and seats[i] = 0 represents that the ith seat is empty (0-indexed).
*
* There is at least one empty seat, and at least one person sitting.
* Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
*
* Return that maximum distance to the closest person.
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
    int maxDistToClosest(vector<int>& seats) {
        int longest = 0, beginning = 0, i = 0;

        // count zeros in beginning
        while (seats[i] == 0) {
            beginning++;
            i++;
        }

        // find longest sequence of zeros in middle
        int count = beginning;
        for (; i< seats.size(); i++) {
            if (seats[i] == 0){
                count++;
            }else {
                longest = max(count, longest);
                count = 0;
            }
        }

        // at the end, count = length of zeros in the end
        // in the middle we have to divide the length in two to find maximum distance
        longest = longest % 2 == 0 ? longest/2 : longest/2+1;

        // return the largest distance
        return max({longest, count, beginning});
    }
};

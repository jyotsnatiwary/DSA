/*You are given with an array (of size N) consisting of positive and negative integers that contain numbers in random order.
Write a program to return true if there exists a sub-array whose sum is zero else, return false.
Input Format :
Line 1 : An Integer N i.e. size of array 
Line 2 : N integers, elements of the array (separated by space)
Output Format :
true or false
Constraints :
1 <= N <= 10^5
Sample Input 1 :
6 
7 1 3 -4 5 1
Sample Output 1 :
true
Sample Input 2 :
5 
-6 7 6 2 1
Sample Output 2 :
false*/

#include<bits/stdc++.h>
using namespace std;
bool subArrayZeroSum(int input[], int n) {
	unordered_set<int> sumSet; 
    // Traverse through array and store prefix sums 
    int sum = 0; 
    for (int i = 0 ; i < n ; i++) 
    { 
        sum += input[i]; 
        // If prefix sum is 0 or it is already present 
        if (sum == 0 || sumSet.find(sum) != sumSet.end()) 
            return true;   
        sumSet.insert(sum); 
    } 
    return false; 
}



/*Maximum Profit on App
Send Feedback
You have made a smartphone app and want to set its price such that the profit earned is maximised. There are certain buyers who will buy your app only if their budget is greater than or equal to your price.
You will be provided with a list of size N having budgets of buyers and you need to return the maximum profit that you can earn.
Lets say you decide that price of your app is Rs. x and there are N number of buyers. So maximum profit you can earn is :
 m * x
where m is total number of buyers whose budget is greater than or equal to x.
Input format :
Line 1 : N (No. of buyers)
Line 2 : Budget of buyers (separated by space)
Output Format :
 Maximum profit
Constraints :
1 <= N <= 10^6
Sample Input 1 :
4
30 20 53 14
Sample Output 1 :
60
Sample Output 1 Explanation :
Price of your app should be Rs. 20 or Rs. 30. For both prices, you can get the profit Rs. 60.
Sample Input 2 :
5
34 78 90 15 67
Sample Output 2 :
201
Sample Output 2 Explanation :
Price of your app should be Rs. 67. You can get the profit Rs. 201 (i.e. 3 * 67).*/

#include<bits/stdc++.h>
using namespace std;

int maximumProfit(int budget[], int n) {
    // Write your code here
	sort(budget,budget+n);
	int cost[n];
	for(int i=0;i<n;i++)
	{
		cost[i]=budget[i]*(n-i);
	}
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(cost[i]>max) max=cost[i];
	}
	return max;
}


/*Chef is playing a game. Currently in the game, he is at a field full of stones. There are total N kinds of stones. There is unlimited supply of each kind of stone.

Chef knows that one stone of kind i needs Ai minutes to pick it from the ground and it will give Chef a profit of Bi Rs.

Chef has K minutes of free time. During this free time, Chef want to pick stones so as to maximize his profit. But he can not pick stones of different kinds, he has to pick stones of a single kind.

Please help Chef to find the maximal possible profit.

Input
First line contains single integer T denoting the number of test cases.
First line of each test case contains two integers N and K.
Next line contains N integers Ai denoting the time needed to pick one stone of kind i.
Next line contains N integers Bi denoting the profit due to picking ithth stone.
Output
For each test case, print a single line containing maximal possible profit.
Constraints
1 = T = 5
1 = N = 105
1 = K = 109
1 = Ai, Bi = 109
Subtasks
Subtask N = 5, T = 2 Points: 30
Subtask N = 105, T = 5 Points: 70
Example
Input:
1
3 10
3 4 5
4 4 5

Output:
12
Explanation
If Chef picks stones of first kind he can pick 3 stones, he will get a profit of 3*4 = 12 Rs.
If Chef picks stones of second kind he can pick 2 stones, he will get a profit of 2*4 = 8 Rs.
If Chef picks stones of third kind he can pick 2 stones, he will get a profit of 2*5 = 10 Rs.

So the maximum possible profit is 12.*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,maxi=0,fuck;
		cin>>n>>k;
		int a[n],b[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		for(int i=0;i<n;i++){
			fuck=(k/a[i])*b[i];
			if(maxi<fuck)maxi=fuck;
		}
		cout<<maxi<<endl;
		}
		
	return 0;
}

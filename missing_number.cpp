#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n, total=0, sum=0;
	cin >> n;
	long long int *arr = new long long int[n-1];
	for ( int i = 0; i < n-1; i++)
	{
			cin>>arr[i];
			sum += arr[i];
	}
	total = (n*(n+1))/2;
	long long ans = total - sum;
	cout << ans;
	return 0;
}

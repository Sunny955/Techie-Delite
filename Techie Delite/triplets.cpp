/* We are given an array and we have to determine pairs of number that are in such a way that i<j<k and arr[i] > arr[j] > arr[k]  this is known as inversion in an array*/
// O(n^2) Solution
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k,temp,size,num=0,count1=0,count2=0;
	cin >> size;
	vector<int> arr(size);
	for(i=0;i<size;i++)
		cin >> arr[i];
	for(j=1;j<size-1;j++)
	{
		count1 = count2 = 0;
		for(i=0;i<j;i++)
		{
			if(arr[j] < arr[i])
				++count1;
		}
		for(k=j+1;k<size;k++)
		{
			if(arr[j] > arr[k])
				++count2;
		}
		num += count1 * count2;
	}
	cout << num << endl;
	return 0;
}
//O(n^3) Solution can be easily be formed by iterating over the array using i,j and k by naive approach


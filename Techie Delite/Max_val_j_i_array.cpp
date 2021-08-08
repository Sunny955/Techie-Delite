/*
Find the maximum value of `j – i` such that `A[j] > A[i]` in an array

Input:  [9, 10, 2, 6, 7, 12, 8, 1]
 
Output: 5 (i = 0, j = 5)
 
 
Input:  [9, 2, 1, 6, 7, 3, 8]
 
Output: 5 (i = 1, j = 6)
 
 
Input:  [8, 7, 5, 4, 2, 1]
 
Output: -1
*/
#include<bits/stdc++.h>
using namespace std;

int MaxValue(vector<int>& input)
{
    vector<pair<int,int>> store;
    int n=input.size();
    for(int i=0;i<n;i++)
    {
        store.push_back({input[i],i});
    }
    
    sort(store.begin(),store.end());
    int ans=-1;
    int max_now=-1000;
    for(int i=n-1;i>=0;i--)
    {
        int indx=store[i].second;
        if(indx>max_now)
        {
            max_now=indx;
        }
        else
        {
            ans=max(ans,max_now-indx);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> input(n,0);
    
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    
    cout<<MaxValue(input)<<endl;
}
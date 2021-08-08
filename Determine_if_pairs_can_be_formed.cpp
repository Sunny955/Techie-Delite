/*
Determine whether an array can be divided into pairs with a sum divisible by `k`
Input:
arr[] = { 3, 1, 2, 6, 9, 4 }
k = 5
 
Output: Pairs can be formed
 
Explanation: Array can be divided into pairs {(3, 2), (1, 9), (4, 6)} where the sum of elements in each pair is divisible by 5.
 
 
Input:
arr[] = { 2, 9, 4, 1, 3, 5 }
k = 6
 
Output: Pairs can be formed
 
Explanation: Array can be divided into pairs {(2, 4), (9, 3), (1, 5)} where the sum of elements in each pair is divisible by 5.
 
 
Input:
arr[] = { 3, 1, 2, 6, 9, 4 }
k = 6
 
Output: Pairs cannot be formed
 
Explanation: Array cannot be divided into pairs where the sum of elements in each pair is divisible by 6.
*/
#include<bits/stdc++.h>
using namespace std;

bool intoPairs(vector<int>& in,int k)
{
    unordered_map<int,int> map;
    for(int i=0;i<in.size();i++)
    {
        int a=in[i]%k;
        if(map.find(a)==map.end())
        {
            map[a]=1;
        }
        else
        {
            map[a]++;
        }
    }
    bool flag=true;
    for(int i=0;i<in.size();i++)
    {
        int f=in[i]%k;
        if(map[f]>0)
        {   
            map[f]--;
            
            if(map.find(k-f)!=map.end() && map[k-f]>0)
            {
                map[k-f]--;
            }
            else
            {
                flag=false;
                break;
            }
        }
    }
    return flag;
    
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> in(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    if(intoPairs(in,k))
    {
        cout<<"Pairs can be formed \n";
    }
    else
    {
        cout<<"Pairs can't formed"<<endl;
    }
}

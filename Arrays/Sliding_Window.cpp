/*
Maximum Sum Subarray of Size k (Sliding Window Technique):

Input:
5
7 20 2 3 4
3

Output:
29 -> 7 + 20 + 2

*/
#include<bits/stdc++.h>
using namespace std;

int BruteForce_Solution(vector<int> v, int size, int k)
{
    //Time Complexity = O(Size * K)
    //Auxiliary Space = O(1)
    int window_sum=0;
    int max_sum = INT_MIN;

    for(int i=0;i<=size-k;i++)
    {
        window_sum=0;
        window_sum+=v[i];
        for(int j=1;j<k;j++)
        {
            
            window_sum +=v[i+j];
            //cout<<"i "<<i<<" j "<<j<<" ws "<<window_sum<<endl;
        }
        max_sum = max(window_sum,max_sum);
        //cout<<"i "<<i<<" max_sum "<<max_sum<<endl;
        //cout<<endl;
    }
    return max_sum;
} 

int Better_Solution(vector<int> v, int size, int k)
{
    //Sliding Window Algorithm
    //Time Complexity = O(Size)
    //Auxiliary Space = O(1)
    int win_sum =0;
    int max_sum=0;
    for(int i=0;i<k;i++)
    {
        win_sum +=v[i];
    }
    max_sum = win_sum;
    //cout<<"win sum "<<win_sum<<" max sum "<<max_sum<<endl;
    for(int i=k;i<size;i++)
    {
        win_sum = win_sum + v[i] - v[i-k];
        max_sum = max(max_sum,win_sum);
    }
    return max_sum;
}

int main()
{
    int size;
    cin>>size;
    vector<int> v;
    for(int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int k;
    cin>>k;

    int max_sum;

    max_sum = BruteForce_Solution(v,size,k);
    cout<<"Max sum of consicutive k elements(BruteForce Solution): "<<max_sum<<endl;

    max_sum = Better_Solution(v,size,k);
    cout<<"Max sum of consicutive k elements(Better Solution): "<<max_sum<<endl;
}
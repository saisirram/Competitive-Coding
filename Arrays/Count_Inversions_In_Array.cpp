/*
Count inversions in an array:
Reference Link: https://takeuforward.org/data-structure/count-inversions-in-an-array/
Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array? Definition: 
for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Input 1:
5
1 2 3 4 5

Output:
0

Explanation:
we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. 
More clear example: 2 has index 1 and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an inversion.

Input 2:
5
5 4 3 2 1

Output:
10

Explanation: 
we have a reverse sorted array and we will get the maximum inversions as for i < j we will always find a pair such that A[j] < A[i]. 
Example: 5 has index 0 and 3 has index 2 now (5,3) pair is inversion as 0 < 2 and 5 > 3 which will satisfy out conditions 
and for reverse sorted array we will get maximum inversions and that is (n)*(n-1) / 2.
For above given array there is 4 + 3 + 2 + 1 = 10 inversions.

Input 3:
5
5 3 2 1 4

Output:
7
*/
#include<bits/stdc++.h>
using namespace std;

int BruteForce_Solution(vector<int> v, int n)
{
    //Time Complexity = O(N * N)
    //Auxiliary Space = O(1)
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[i])
            {
                count++;
            }
        }
    }
    return count;
}

//Merge Sort Implementation
int Merging(vector<int> v, int low, int mid, int high)
{
    int i=low;
    int j = mid;
    int k = low;
    int inv_count = 0;

    while((i<= mid -1) && (j<=high))
    {
        if(v[i]<v[j])
        {
            i++;
        }
        else{
            j++;
            inv_count += (mid - i);
        }
    }

    return inv_count;
}

int Merge_Sort(vector<int> v, int low, int high)
{
    int mid;
    mid = (low + high)/2;

    int m_count =0;
    m_count += Merge_Sort(v,low,mid);
    m_count += Merge_Sort(v, mid+1, high);

    m_count += Merging(v,low,mid+1,high);
    return m_count;
}

int Better_Solution(vector<int> v, int n)
{
    //Merge Sort Technique
    //Time Complexity = O(NLogN) (Merge Sort)
    //Auxiliary Space = O(N) (temp array)
    vector<int> temp(n,0);
    int count =0;
    count = Merge_Sort(v,0,n-1);
    return count;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    int inversion_count;

    inversion_count = BruteForce_Solution(v,n);
    cout<<"No of Inversions in the array are(BruteForce Solution): "<<inversion_count<<endl;
    
    inversion_count = BruteForce_Solution(v,n);
    cout<<"No of Inversions in the array are(Better Solution): "<<inversion_count<<endl;
    
    return 0;
}
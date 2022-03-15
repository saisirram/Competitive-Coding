/*
Count Reverse Pairs:
Reference Link: https://takeuforward.org/data-structure/count-reverse-pairs/
Given an array of numbers, you need to return the count of reverse pairs. 
Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

Input 1:
5
0 3 2 4 1

Output:
2

Explanation:
2 pairs are (3,1) -> (3 > 2*1) and (4,1) -> (4 > 2*1) 

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
            if(2*v[j]<v[i])
            {
                count++;
            }
        }
    }
    return count;
}

//Merge Sort Implementation
int Merging(vector<int> &v, int low, int mid, int high)
{
    int j = mid+1;
    int inv_count = 0;
    for(int i=low;i<=mid;i++)
    {
        cout<<"FOR "<<endl;
        while(j<=high && v[i]>2*v[j])
        {
            j++;
        }
        
        inv_count += (j-(mid +1));
       
    }
    int l=low;
    int r = mid +1;
    int k = low;
    vector<int> t;
    while((l<= mid) && (r<=high))
    {
        if(v[l]<=v[r])
        {
            t.push_back(v[l++]);
        }
        else{
            t.push_back(v[r++]);
        }
    }
    while(l<=mid)
    {
        t.push_back(v[l++]);
    }
    while(r<=high)
    {
        t.push_back(v[r++]);
    }

    for(int i=low;i<=high;i++)
    {
        v[i] = t[i - low];
    }
    return inv_count;
}

int Merge_Sort(vector<int> &v, int low, int high)
{
    
    if(low>=high) return 0;
    int mid;
    mid = (low + high)/2;

    int m_count;
    m_count = Merge_Sort(v,low,mid);
    m_count += Merge_Sort(v, mid+1, high);

    m_count += Merging(v,low,mid,high);
    return m_count;
}

int Better_Solution(vector<int> &v, int n)
{
    //Merge Sort Technique
    //Time Complexity = O(NLogN) (Merge Sort)
    //Auxiliary Space = O(N) (temp array)
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
    
    inversion_count = Better_Solution(v,n);
    cout<<"No of Inversions in the array are(Better Solution): "<<inversion_count<<endl;
    
    return 0;
}
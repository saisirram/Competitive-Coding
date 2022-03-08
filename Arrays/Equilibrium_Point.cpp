/*
Equilibrium Point or Pivotal Point or Middle Idx in Array:
The index at which left sum is equal to its right sum is called Equilibrium Point.

Input 1:
6
1 7 3 6 5 6

Output:
3

Explanation: 
lsum till idx 3 = 1 + 7 + 3 = 11
rsum right of idx 3  = 5 + 6 = 11

Input 2:
3
2 1 -1

Output:
0

Explanation:
lsum of idx 0 = 0 (since the is no left elements)
rsum of idx 0 = 1 + (-1) = 0

Input 3:
3
1 2 3

Output:
-1

Explanation:
at any idx lsum != rsum
*/

#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v, int size)
{
     for(int i=0;i<size;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

/*
For each Idx calculate leftsum and rightsum.
if both are equaal then it is the equilibrium point.
*/
int BruteForce_Soluion(vector<int> v, int size)
{
    //Time Complexity = O(Size^2)
    //Auxiliary Space = O(1)
    int lsum =0;
    int rsum =0;
    for(int i =0; i<size;i++)
    {
        lsum =0;
        for(int j=0;j<i;j++)
        {
            lsum += v[j];
        }
        rsum =0;
        for(int k=i+1;k<size;k++)
        {
            rsum += v[k];
        }
        if(rsum == lsum)
        {
            return i;
        }
    }
    return -1;
}

/*
caluculate prefix(left sum) and suffix sum(right sum) arrays.
at any idx if prefix sum == suffix sum then that idx is Equilibrium point.
*/
int Better_Solution(vector<int> v, int size)
{
    //Time Complexity = O(Size) + O(Size) + O(Size) = O(3Size) => O(Size)
    //Auxiliary Space = O(Size) + O(Size) = O(2Size) => O(Size)
    vector<int> prefix_sum(size,0);
    vector<int> suffix_sum(size,0);
    prefix_sum[0]=v[0];
    suffix_sum[size-1] = v[size -1];

    for(int i=1;i<size;i++)
    {
        prefix_sum[i] = prefix_sum[i-1] + v[i];
    }

    for(int i=size-2;i>=0;i--)
    {
        suffix_sum[i] = suffix_sum[i+1] + v[i];
    }
    //print_vector(prefix_sum,size);
    //print_vector(suffix_sum,size);
    
    for(int i=0;i<size;i++)
    {
       if(prefix_sum[i] == suffix_sum[i])
       {
           return i;
       }
    }
    return -1;
}

/*
In-Order to get equilibrium point its left sum must be equal to its right sum.
so firstly we calculate the total sum of array.
now we traverse the array from left to right and adding each element to its left to lsum.
to get right sum what we do is fro total sum exclude the element at that index,
and also exclude the left sum until that index -> rsum = (total_sum - v[i] - lsum)
so if rsum == lsum  then return that index.
*/
int Best_Solution(vector<int> v, int size)
{
    //Time Complexity = O(Size)
    //Auxiliary Space = O(1)
    int total_sum = accumulate(v.begin(),v.end(),0); // O(Size)
    int lsum =0;

    for(int i=0;i<size;i++) // O(Size)
    {
        if(lsum == (total_sum - v[i] - lsum))
        {
            return i;
        }
        lsum += v[i];
    }
    return -1;
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
    int idx;

    idx = BruteForce_Soluion(v,size);
    cout<<"Equilibrium Point (BruteForce Solution): "<<idx<<endl;

    idx = Better_Solution(v,size);
    cout<<"Equilibrium Point (Better Solution): "<<idx<<endl;

    idx = Best_Solution(v,size);
    cout<<"Equilibrium Point (Best Solution): "<<idx<<endl;
}
/*
Maximum circular subarray sum:
Given n numbers (both +ve and -ve), arranged in a circle, 
find the maximum sum of consecutive numbers.

Input:
3
5 -3 5

Output:
10 ->[5,5]

*/
#include<bits/stdc++.h>
using namespace std;

int BruteForce_Solution(vector<int> v, int size)
{
    int result = v[0];
    int curr_sum,max_sum;

    for(int i=0;i<size;i++)
    {
        curr_sum = v[i];
        max_sum = v[i];
        for(int j=1;j<size;j++)
        {
            int idx = (i+j)%size;
            curr_sum+=v[idx];
            max_sum = max(curr_sum,max_sum);
        }
        result = max(result,max_sum);
    }
    return result;
}

int Better_Solution(vector<int> v, int size)
{
    /*Inorder to get max sum contiguos circular subarray then we need to do two things.
        1) Max sum subarray in normal array (Kaanes Algo) -> max_sum_normal
        2) Min sum subarray in normal array (Modified Kadanes algo) -> min_sum

        the to get max sum in contiguous subarray then the formula is:
        max_sum_circular = max(max_sum_normal,(total_array_sum - min_sum))
    */
    //Calculate Max Sum Subarray
    int maxsf =INT_MIN;
    int maxeh = 0;
    for(int i=0;i<size;i++)
    {
        maxeh += v[i];
        if(maxeh>maxsf)
        {
            maxsf = maxeh;
        }
        if(maxeh<0)
        {
            maxeh = 0;
        }
    }
    cout<<"max so far:"<<maxsf<<endl;
    //calculates minimum sum subarray.
    int mineh = INT_MAX;
    int minsf = INT_MAX;

    for(int i=0;i<size;i++)
    {
        if(mineh>0)
        {
            mineh = v[i];
        }
        else{
            mineh +=v[i];
        }
        minsf = min(mineh,minsf);
    }
    cout<<"min so far:"<<minsf<<endl;
    //calculate total array sum
    int initial_sum =0;
    int total_array_sum = accumulate(v.begin(), v.end(),initial_sum);
    cout<<"total sum:"<<total_array_sum<<endl;

    return max(maxsf,(total_array_sum - minsf));
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

    int max_sum;
    max_sum = BruteForce_Solution(v,size);
    cout<<"Max sum of a circular subarray(BruteForce Solution): "<<max_sum<<endl;

    max_sum = Better_Solution(v,size);
    cout<<"Max sum of a circular subarray(Better Solution): "<<max_sum<<endl;
}
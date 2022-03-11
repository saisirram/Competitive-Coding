/*
Find the repeating and missing numbers
You are given a read-only array of N integers with values also in the range [1,N] both inclusive. 
Each integer appears exactly once except A which appears twice and B which is missing. 
The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

Input:
10
2 5 4 6 9 3 8 9 7 1

Output:
Missing Element = 10
Repeating Element = 9
*/
#include<bits/stdc++.h>
using namespace std;
/*
BruteForce Solution:
Use Hash Map or Frequency array. Traverse the array and store their occurance in hash map or frequency array.
now check the Hash map or frequency array for the count if the count of an element is greater than 1 then it is repeating element.
if count in the frequency array or hash map is 0 then it is missing Element.
Time Complexity = O(N)
Auxiliary Space = O(N) (for Hash map or Frequency array)
*/

vector<int> Best_Solution(vector<int> v, int n)
{
    //Solution Migh Overflow
    //Time Complexity = O(N)
    //Auxiliary Space = O(1)
    long long int sum_of_n = n*(n+1)/2;
    long long int sq_of_n = (n*(n+1)*(2*n+1))/6;
    vector<int> ans;

    for(int i=0; i<n; i++)
    {
        sum_of_n -= (long long int)v[i];
        sq_of_n -= (long long int)v[i] * (long long int)v[i];
    }

    long long int missing = (sum_of_n + sq_of_n/sum_of_n)/2;
    long long int repeating =  missing - sum_of_n;

    ans.push_back((int)missing);
    ans.push_back((int)repeating);

    return ans;
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

    vector<int> res = Best_Solution(v,n);
    cout<<"Missing Element int the array is: "<<res[0]<<endl;
    cout<<"Repeating Element int the array is: "<<res[1]<<endl;
    return 0;
}
/*
Longest Consecutive Sequence in an Array:
Reference Link: https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array
You are given an array of ‘N’ integers. You need to find the length of the longest sequence 
which contains the consecutive elements.

Input 1:
7
101 4 100 102 3 1 2

Output:
4 -> [1 2 3 4] longest Consecutive Sequence.

Input 2:
7
10 20 30 40 50 60 70

Output:
1 -> there are no consecutiv numbers of size more than one. each single element is considered as consecutive.
*/

#include<bits/stdc++.h>
using namespace std;

int BruteForce_Solution(vector<int> v, int n)
{
    //Time Complexity = O(NLogN) + O(N)
    //Auxiliary Space =O(N) //for sort function
    sort(v.begin(),v.end()); //O(NLogN) time + O(N) space
    int count =1;
    int prev = v[0];
    int ans =0;
    for(int i=1;i<n;i++)//O(N)
    {
        if(v[i] == prev +1)
        {
            count +=1;
        }
        else{
            count =1;
            
        }
        prev = v[i];
        ans = max(ans,count);
    }
    return ans;
}

int Better_Solution(vector<int> v, int n)
{
    //Time Complexity = O(N) + O(N)
    //Auxiliary Space = (N)
    unordered_set<int> hashSet; //Space O(N)
    for(int num : v)//O(N)
    {
        hashSet.insert(num);
    }

    int max_streak =0;
    for(int i=0;i<n;i++)//O(N)
    {
        if(!hashSet.count(v[i]-1)) // In unordered Set count operation take O(1) time
        {
            int currentNum = v[i];
            int currentStreak = 1;

            while(hashSet.count(currentNum + 1))
            {
                currentStreak += 1;
                currentNum += 1;
            }
            max_streak = max(max_streak,currentStreak);
        }
        
    }
    return max_streak;
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

    int result;
    result = BruteForce_Solution(v,n);
    cout<<"Length Largest Consecutive Sequence(BruteForce Solution): "<<result<<endl;

    result = Better_Solution(v,n);
    cout<<"Length Largesrt Consecutive Sequence(Better Solution): "<<result<<endl;

    return 0;
}
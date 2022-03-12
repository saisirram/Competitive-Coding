/*
Implement Pow(x,n) | X raised to the power N:
Reference link: https://takeuforward.org/data-structure/implement-powxn-x-raised-to-the-power-n/
Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).

Input 1:
2.0 10

Output:
1024

Input 2:
2.1000 3

Output:
9.261

Input 3:
2.0 -2

Output:
0.25
*/
#include<bits/stdc++.h>
using namespace std;

double BruteForce_Solution(double x,int n)
{
    //Time Complexity = O(N)
    //Auxiliary Space = O(1)
    double ans = 1.0;
    long nn = n;
    if(n<0)
    {
        nn =-1*n;
    }

    for(int i=1;i<=nn;i++)
    {
        ans *= x;
    }

    if(n<0)
    {
        return 1.0/ans;
    }
    else{
        return ans;
    }
}

double Better_Solution(double x, int n)
{
    //Time Complexity = O(log N)
    //Auxiliary Space = O(1)
    double ans = 1.0;
    long long nn = n;
    if(n<0)
    {
        nn =-1*n;
    }

    while(nn>0)
    {
        if(nn%2 == 0)
        {
            x =x*x;
            nn = nn/2;
        }
        else{
            ans = ans * x;
            nn = nn -1;
        }
    }

    if(n<0)
    {
        return 1.0/ans;
    }
    else{
        return ans;
    }
}

int main()
{
    double x;
    int n;
    cin>>x>>n;

    double ans;
    ans = BruteForce_Solution(x,n);
    cout<<x<<" to the powe of "<<n<<" is equals to "<<ans<<endl;

    ans = Better_Solution(x,n);
    cout<<x<<" to the powe of "<<n<<" is equals to "<<ans<<endl;
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int res =-1,largest =0;

    for(int i=1;i<size;i++)
    {
        if(arr[i]>arr[largest]) // if  arr[i] is greater than 'largest' then 'largest' will be second largest element
        {                       // and arr[i] will be second largest element
            largest =i;
            res = largest;
        }

        else if(arr[i]!=arr[largest])  //condition for elements which are same will not be considered as 2nd largest
        {
            if(res == -1 || arr[i]>arr[res])
            {
                res = i;
            }
        }
    }
    return 0;
}
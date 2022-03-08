/*
Max Difference in an array is arr[j] - arr[i] must be maximum having j>i

Example:
Input:
7 -> size
2 3 10 6 4 8 1

Output:
max difference: 8 (arr[i] = 2 and arr[j] = 10 now arr[j] - arr[i] = 8)
*/

#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int> arr, int size)
{
    for( auto x : arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

void BruteForceSolution(vector<int> arr, int size)
{
    //Time Complexity = O(Size^2)
    //Auxiliary Space = O(1)
    int max_diff = INT_MIN;
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(max_diff< arr[j]-arr[i])
            {
                max_diff = arr[j]-arr[i];
            }
        }
    }
    cout<<"Max Difference: "<<max_diff<<endl;
}

void BetterSolution(vector<int> arr, int size)
{
    //Time Complexity = O(Size)
    //Auxiliary Space = O(1)

    /*
    here in order to get max diff we need arr[i] value must be most min wrt arr[j]
    which means for every ele at j we need to keep track of min ele on its right
    thus by delivering max diff.
    */
    int max_diff = arr[1]- arr[0];
    int min_val = arr[0];
    for(int i=1;i<size;i++)
    {
        if(max_diff< arr[i] - min_val)
        {
            max_diff = arr[i] - min_val;
        }

        if(min_val > arr[i])
        {
            min_val = arr[i];
        }
    }
    cout<<"Max Difference: "<<max_diff<<endl;
}

int main()
{
    int size;
    cin>>size;
    vector<int> arr;
    int x;
    for(int i=0;i<size;i++)
    {
        cin>>x;
        arr.push_back(x);
    }

    cout<<"Original Array: "<<" ";
    print_vector(arr,size);

    BruteForceSolution(arr,size);

    cout<<"Original Array: "<<" ";
    print_vector(arr,size);

    BetterSolution(arr,size);
    
}

//[999,997,980,976,948,940,938,928,924,917,907,907,881,878,864,862,859,857,848,840,824,824,824,805,802,798,788,777,775,766,755,748,735,732,727,705,700,697,693,679,676,644,634,624,599,596,588,583,562,558,553,539,537,536,509,491,485,483,454,449,438,425,403,368,345,327,287,285,270,263,255,248,235,234,224,221,201,189,187,183,179,168,155,153,150,144,107,102,102,87,80,57,55,49,48,45,26,26,23,15
//[999,997,980,976,948,940,938,928,924,917,907,907,881,878,864,862,859,857,848,840,824,824,824,805,802,798,788,777,775,766,755,748,735,732,727,705,700,697,693,679,676,644,634,624,599,596,588,583,562,558,553,539,537,536,509,491,485,483,454,449,438,425,403,368,345,327,287,285,270,263,255,248,235,234,224,221,201,189,187,183,179,168,155,153,150,144,107,102,102,87,80,57,55,49,48,45,26,26,23,15]
#include<bits/stdc++.h>
using namespace std;
void print_array(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/*
BruteForce Solution:
Take a dummy array of size n + m ->(N) . add elements af arr1 and arr2 to that dummy array 
and then sort it. finally overwrite the original array elements with the sorted dummy array elements.

Time Complexity = O(N)(for traversing, adding it in dummy array) + O(NLogN)(sorting) + O(N)(Overwriting original arrays)
Auxiliary Space = O(N)
*/

void Better_Solution(int arr1[], int n, int arr2[], int m)
{
    int k;
    for(int i=0;i<n;i++)
    {
        if(arr1[i] > arr2[0])
        {
            int temp = arr2[0];
            arr2[0] = arr1[i];
            arr1[i] = temp;
        }

        //sort(arr2, arr2 + m);
        int first = arr2[0];
        for(k=1; k<m ;k++)
        {
            if(arr2[k] < first)
            arr2[k-1] = arr2[k];
            else
            break;
        }
        arr2[k-1] = first;
    }
}

void Best_Solution(int arr1[], int n, int arr2[], int m)
{
    int gap = ceil((float)(n+m)/2);
    while (gap > 0) {
    int i = 0;
    int j = gap;
    while (j < (n + m)) {
      if (j < n && arr1[i] > arr1[j]) {
        swap(arr1[i], arr1[j]);
      } else if (j >= n && i < n && arr1[i] > arr2[j - n]) {
        swap(arr1[i], arr2[j - n]);
      } else if (j >= n && i >= n && arr2[i - n] > arr2[j - n]) {
        swap(arr2[i - n], arr2[j - n]);
      }
      j++;
      i++;
    }
    if (gap == 1) {
      gap = 0;
    } else {
      gap = ceil((float) gap / 2);
    }
  }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int j=0;j<m;j++)
    {
        cin>>arr2[j];
    }
    cout<<"Arrays Before Merging: "<<endl;
    print_array(arr1,n);
    print_array(arr2,m);

    //int brut_res[n+m];
    //brut_res = BruteForce_Solution(arr1, n, arr2, m);

    // Better_Solution(arr1,n,arr2,m);
    // cout<<"Arrays After Merging: "<<endl;
    // print_array(arr1,n);
    // print_array(arr2,m);

    Best_Solution(arr1,n,arr2,m);
    cout<<"Arrays After Merging: "<<endl;
    print_array(arr1,n);
    print_array(arr2,m);

    return 0;
}
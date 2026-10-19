#include<iostream>
using namespace std;

void combine(int arr[], int low, int upper, int mid)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[upper - low + 1];

    while(i <= mid && j <= upper)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j <= upper)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int i = low; i <= upper; i++)
    {
        arr[i] = temp[i - low];
    }
}

void MergeSort(int arr[], int low, int upper)
{
    if(low >= upper)
    {
        return;
    }

    int mid = (low + upper) / 2;

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, upper);

    combine(arr, low, upper, mid);
}

int main()
{
    int n;

    cout<<"Enter size of array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    MergeSort(arr, 0, n - 1);

    cout<<"Sorted array: ";

    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;
}

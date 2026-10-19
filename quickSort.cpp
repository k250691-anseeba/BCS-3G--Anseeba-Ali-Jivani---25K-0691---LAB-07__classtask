#include<iostream>
using namespace std;

int partition(int array[], int lowerBound, int upperBound)
{
    int pivot = array[lowerBound];

    int start = lowerBound;
    int end = upperBound;

    while(start < end)
    {
        while(array[start] <= pivot && start < upperBound)
        {
            start++;
        }

        while(array[end] > pivot)
        {
            end--;
        }

        if(start < end)
        {
            swap(array[start], array[end]);
        }
    }

    swap(array[lowerBound], array[end]);

    return end;
}

void QuickSort(int array[], int lowerBound, int upperBound)
{
    if(lowerBound < upperBound)
    {
        int location = partition(array, lowerBound, upperBound);

        QuickSort(array, lowerBound, location - 1);
        QuickSort(array, location + 1, upperBound);
    }
}

int main()
{
    int n;

    cout<<"Enter size of array: ";
    cin>>n;

    int array[n];

    cout<<"Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin>>array[i];
    }

    QuickSort(array, 0, n - 1);

    cout<<"Sorted array: ";

    for(int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }

    cout<<endl;

    return 0;
}

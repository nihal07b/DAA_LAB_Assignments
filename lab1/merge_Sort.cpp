// Nihal
// 25/DA/048
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int si, int mid, int ei)
{
    vector<int> help;
    int i = si;
    int j = mid + 1;
    while (i <= mid && j <= ei)
    {
        if (arr[i] > arr[j])
        {
            help.push_back(arr[j]);
            j++;
        }
        else
        {
            help.push_back(arr[i]);
            i++;
        }
    }

    while (i <= mid)
    {
        help.push_back(arr[i]);
        i++;
    }
    while (j <= ei)
    {
        help.push_back(arr[j]);
        j++;
    }

    for (int idx = si, x = 0; idx <= ei; idx++, x++)
    {
        arr[idx] = help[x];
    }
}

void mergesort_R(vector<int> &arr, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = si + (ei - si) / 2;

    mergesort_R(arr, si, mid);
    mergesort_R(arr, mid + 1, ei);

    merge(arr, si, mid, ei);
}

void mergesort_I(vector<int> &arr,int si,int ei){
    int n=arr.size();

    for(int size=1;size<n;size*=2){
        for(int si=0;si<n-size;si+=2*size){
            int mid=si+size-1;

            int ei=min(si+2*size-1,n-1);

            merge(arr,si,mid,ei);
        }
    }
}

int main()
{
    vector<int> arr = {7,8,11,9,13,12,18,6};
    // mergesort_R(arr,0,arr.size()-1);
    mergesort_I(arr,0,arr.size()-1);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
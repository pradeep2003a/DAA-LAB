#include<bits/stdc++.h>
using namespace std;

class QuickSort
{
    int temp,high,low;
public:
    void swap(int *, int *);
    int partition(int *, int , int);
    void sort(int *, int, int);
};

 // SWAPPING FUNTION 
void QuickSort::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// PARTITION FUNTION BY PIVOT AS LAST ELEMENT
int QuickSort::partition(int a[], int low, int high)
{
    int key = a[high];
    int i = (low-1);
    for (int j = low; j <= high-1; j++)
    {
        if (a[j] < key)
        {
            i++;
            swap(&a[i], &a[j]);
        }
        swap(&a[i++], &a[high]);
        return (i+1);
    }
}

// SORTING FUNTION USING RECURSION
// TRAVERSAL: PRE-ORDER TRAVERSAL
void QuickSort::sort(int a[], int low, int high)
{
    if(low < high){
        int j = partition(a, low, high);
        sort(a, low, j-1);
        sort(a, j+1, high);
    }
}

int main()
{
    int *a, n, i;
    clock_t start, stop;
    QuickSort qs;
    cout<<"Enter number of elements: ";
    cin>>n;
    a = new int[n];
    cout<<"Enter the elements: "<<endl;
    for(i=0; i<n; i++)
        cin>>a[i];
    start = clock();
    qs.sort(a, 0, n-1);
    stop = clock();
    cout<<"Sorted Elements are: "<<endl;
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n\n";
    cout<<"TIME TAKEN = "<<(stop-start)/CLK_TCK<< " SECONDS."<<endl;
    cout<<"SPACE CONSUMED = "<< sizeof(n)+ n*sizeof(a) + sizeof(i) + sizeof(qs) << " BYTES."<< endl;
    cout<<"\n\n";
}
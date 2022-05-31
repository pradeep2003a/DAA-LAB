#include <iostream>
#include <conio.h>
#include <time.h>
#define MAX 100000
using namespace std;

class MergeSort
{
    int begin, end;

public:
    void Sort(int *, int, int);
    void Merge(int *, int, int, int);
};

// MERGE ALGORITHM
void MergeSort::Sort(int a[], int begin, int end)
{
    if (begin < end) // Check whether index of begin is less than end
    {
        int mid = (begin + end) / 2; // Find the mid point and divide the array
        Sort(a, begin, mid);         // Using recursion do the division to first part
        Sort(a, mid + 1, end);       // Divide the second part
        Merge(a, begin, mid, end);   // Sort And Merge The Divided Array
    }
}

// MERGE THE SPLITTED ARRAY BY COMPARING AND TRAVERSAL LIKE A TREE
void MergeSort::Merge(int a[], int begin, int mid, int end)
{
    // Initialize all the params
    int i = begin;   // Index Of Left SubArray
    int j = mid + 1; // Index Of Right SubArray
    int k = begin;   // Index Of MergedArray
    int temp[MAX];   // Temporary array to copy the contents

    while (i <= mid && j <= end)
    {
        // Compare the left subarray and right subarray
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }

    // In case if any element is left out Merge it out
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= end)
        temp[k++] = a[j++];
    // Move All The Merged Array from temp[] to Main array a[]
    for (i = begin; i <= end; i++)
        a[i] = temp[i];
}

// Driver Function
int main()
{
    int *a, n, i;
    clock_t start, stop;
    MergeSort Sort;
    cout << "Enter the number of elements: ";
    cin >> n;
    a = new int[n];
    cout << "\nEnter the elements: " << endl;
    for (i = 0; i < n; i++)
    {
        a[i] = rand();
    }

    start = clock();
    Sort.Sort(a, 0, n - 1);
    stop = clock();

    cout << "\nSorted Elements are: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n\n";
    cout << "TIME TAKEN = " << (double)(stop-start) / CLOCKS_PER_SEC  << " SECONDS." << endl;
    cout << "SPACE CONSUMED = " << sizeof(n) + n * sizeof(a) + sizeof(i) + sizeof(Sort) << " BYTES." << endl;
    getch();
    return 0;
}

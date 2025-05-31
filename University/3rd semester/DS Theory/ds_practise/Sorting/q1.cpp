#include <iostream>
#include <algorithm>

using namespace std;

// Function to perform Binary Search to find the correct position
// to insert the current element
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        // If x is smaller, ignore right half
        if (arr[mid] > x)
            r = mid - 1;

        // If x is larger, ignore left half
        else
            l = mid + 1;
    }

    // Return the index at which x should be inserted
    return l;
}

// Function to perform Binary Insertion Sort
void binaryInsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // Find the correct position to insert the current element
        int pos = binarySearch(arr, 0, i - 1, arr[i]);

        // Shift all elements after the insertion point one position to the right
        int temp = arr[i];
        for (int j = i; j > pos; j--)
            arr[j] = arr[j - 1];
        arr[pos] = temp;
    }
}

// Driver code
int main()
{
    int arr[] = {37, 23, 0, 17, 12, 72, 31,
                 46, 100, 88, 54};
    int n = sizeof(arr) / sizeof(arr[0]);

    binaryInsertionSort(arr, n);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

// Structure to store the value and index of an element in the array
struct Element
{
    int value;
    int index;
};

// Comparison function to sort the elements in ascending order
bool compare(Element a, Element b)
{
    return a.value < b.value;
}

// Function to perform Indirect Index Sort
int* indirectIndexSort(int* arr, int n)
{
    // Create an array of Element structures
    Element* elements = new Element[n];
    for (int i = 0; i < n; i++)
    {
        elements[i].value = arr[i];
        elements[i].index = i;
    }

    // Sort the elements in ascending order
    sort(elements, elements + n, compare);

    // Create the sorted index array
    int* sortedIndexes = new int[n];
    for (int i = 0; i < n; i++)
        sortedIndexes[i] = elements[i].index;

    // Deallocate the elements array
    delete[] elements;

    return sortedIndexes;
}

// Driver code
int main()
{
    int arr[] = {13, 29, 91, 34, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* sortedIndexes = indirectIndexSort(arr, n);

    cout << "Sorted index array: ";
    for (int i = 0; i < n; i++)
        cout << sortedIndexes[i] << " ";

    // Deallocate the sortedIndexes array
    delete[] sortedIndexes;

    return 0;
}

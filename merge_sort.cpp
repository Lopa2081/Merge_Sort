#include <iostream>
using namespace std;

// Forward declaration of Merge
void Merge(int a[], int l, int mid, int h);

// MergeSort function
void MergeSort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, h);
        Merge(a, l, mid, h);
    }
}

// Merge function
void Merge(int a[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int temp[100]; // Adjust size if needed

    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    while (j <= h)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    for (int m = l; m <= h; m++)
    {
        a[m] = temp[m];
    }
}

// Main function
int main()
{
    int a[6] = {1, 4, 2, 6, 3, 8};
    int n = sizeof(a) / sizeof(a[0]);

    MergeSort(a, 0, n - 1);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}

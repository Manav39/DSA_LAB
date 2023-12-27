#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                return;
            }
        }
    }

    void deleteElement()
    {
        if (size == 0)
        {
            cout << "Nothing to Delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && arr[leftIndex] > arr[i])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[rightIndex] > arr[i])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;
    if (leftChild <= n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }
    if (rightChild <= n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

void minheapify(int arr[], int n, int i)
{
    int smallest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;
    if (leftChild <= n && arr[leftChild] < arr[smallest])
    {
        smallest = leftChild;
    }
    if (rightChild <= n && arr[rightChild] < arr[smallest])
    {
        smallest = rightChild;
    }
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minheapify(arr, n, smallest);
    }
}

void heapsort_desc(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        minheapify(arr, size, 1);
    }
}

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteElement();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, n);
    cout << "Sorting in Ascending Order" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    heapsort_desc(arr, n);
    cout << "Sorting in Descinding Order" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
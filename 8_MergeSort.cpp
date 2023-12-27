#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int start, int end)
{
    int mid = (start + end) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;
    vector<int> first(len1);
    vector<int> second(len2);
    int k = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = v[k];
        k++;
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = v[k];
        k++;
    }

    int index1 = 0;
    int index2 = 0;
    k = start;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            v[k++] = first[index1++];
        }
        else
        {
            v[k++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        v[k++] = first[index1++];
    }
    while (index2 < len2)
    {
        v[k++] = second[index2++];
    }
}

void mergesort(vector<int> &v, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergesort(v, start, mid);
    mergesort(v, mid + 1, end);
    merge(v, start, end);
}

int main()
{
    int n;
    cout << "Enter the size of the Array : " << endl;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    mergesort(v, 0, n - 1);
    for (int i : v)
    {
        cout << i << " ";
    }
}
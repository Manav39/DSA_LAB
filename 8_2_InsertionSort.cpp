#include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
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

    insertionsort(v);
    for (int i : v)
    {
        cout << i << " ";
    }
    return 0;
}
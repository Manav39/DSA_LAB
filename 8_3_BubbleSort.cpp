#include <bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[i])
            {
                swap(v[i], v[j]);
            }
        }
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

    bubblesort(v);
    for (int i : v)
    {
        cout << i << " ";
    }
    return 0;
}
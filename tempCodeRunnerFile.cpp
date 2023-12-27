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
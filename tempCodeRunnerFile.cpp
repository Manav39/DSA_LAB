vector<bool> visitt(n, false);
    bool res;
    for (int i = 0; i < n; i++)
    {
        if (g.isCyclicDFS(0, -1, visitt))
        {
            if (res == true)
            {
                break;
            }
        }
    }
    if (res)
        cout << "Cycle exists" << endl;
    else
        cout << "Dosent exists" << endl;
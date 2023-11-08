#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process
{
    vector<int> allocated;
    vector<int> maxneed;
    vector<int> remainneed;
};

int main()
{
    int n, d;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of resources: ";
    cin >> d;

    vector<int> available(d);
    for (int i = 0; i < d; i++)
    {
        int res = 0;
        cout << "Enter the initial number of resources for resource " << i << ": ";
        cin >> res;
        available[i] = res;
    }

    vector<Process> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].allocated.resize(d);
        arr[i].maxneed.resize(d);
        arr[i].remainneed.resize(d);
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i << " - Enter the number of resources allocated: ";
        for (int j = 0; j < d; j++)
        {
            int res;
            cin >> res;
            arr[i].allocated[j] = res;
        }

        cout << "Process " << i << " - Enter the Maximum number of resources needed: ";
        for (int j = 0; j < d; j++)
        {
            int res;
            cin >> res;
            arr[i].maxneed[j] = res;
            arr[i].remainneed[j] = arr[i].maxneed[j] - arr[i].allocated[j];
        }
    }

    vector<bool> finished(n, false);
    vector<int> ans;
    int j = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!finished[i])
            {
                bool check = true;
                for (int r = 0; r < d; r++)
                {
                    if (arr[i].remainneed[r] > available[r])
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    for (int r = 0; r < d; r++)
                    {
                        available[r] += arr[i].allocated[r];
                    }
                    finished[i] = true;
                    ans.push_back(i);
                }
            }
        }
    }

    bool safe = true;
    for (int i = 0; i < n; i++)
    {
        if (!finished[i])
        {
            safe = false;
            break;
        }
    }

    if (safe)
    {
        cout << "Safe Sequence: ";
        for (int i : ans)
        {
            cout << "P" << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No safe sequence exists." << endl;
    }

    return 0;
}
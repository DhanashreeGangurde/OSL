#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n, d, m;
    cout << "Enter the number of requests: ";
    cin >> n;
    cout << "Enter the current trailhead's position: ";
    cin >> d;
    cout << "Enter the maximum disk size: ";
    cin >> m;
    m = m - 1;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Request " << i + 1 << ": ";
        cin >> arr[i];
    }
    bool go = true; 
    int choice = 0;
    int total_time = 0;

    while (go)
    {
        cout << "\nChoice from the following Disk Scheduling Algorithm : \n1) SSTF\n2) SCAN\n3) C-Look\n4) Exit\n";
        cout << "Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            total_time = 0;

            while (true)
            {
                int min_distance = INT_MAX;
                int next_index = -1;

                for (int i = 0; i < n; i++)
                {
                    if (arr[i] != -1)
                    {
                        int distance = abs(arr[i] - d);
                        if (distance < min_distance)
                        {
                            min_distance = distance;
                            next_index = i;
                        }
                    }
                }

                if (next_index == -1)   
                {
                    break;
                }

                total_time += min_distance;
                d = arr[next_index];
                arr[next_index] = -1;
            }

            cout << "Total time: " << total_time << endl;
        }
        else if (choice == 2)
        {
            vector<int> ans(arr.begin(), arr.end());
            // Corrected code for SCAN (left and right directions)
            string dir;
            cout << "Enter the Direction (left or right): ";
            cin >> dir;

            if (dir != "left" && dir != "right")
            {
                cout << "Invalid direction." << endl;
                continue;
            }

            if (dir == "left")
            {
                total_time = m - d;
                int min = INT_MAX;
                for (int i = 0; i < n; i++)
                {
                    if (ans[i] < min)
                    {
                        min = ans[i];
                    }
                }
                total_time += m - min;
            }
            else
            {
                total_time = d;
                int max = INT_MIN;
                for (int i = 0; i < n; i++)
                {
                    if (ans[i] > max)
                    {
                        max = ans[i];
                    }
                }
                total_time += max;
            }

            cout << "Total time: " << total_time << endl;
        }
        else if (choice == 3)
        {
            vector<int> ans(arr.begin(), arr.end());
            // Corrected code for C-Look (left and right directions)
            string dir;
            cout << "Enter the Direction (left or right): ";
            cin >> dir;

            if (dir != "left" && dir != "right")
            {
                cout << "Invalid direction." << endl;
                continue;
            }

            if (dir == "left")
            {
                int max = d;

                for (int i = 0; i < n; i++)
                {
                    if (max <= ans[i])
                    {
                        max = ans[i];
                    }
                    if (d <= ans[i])
                    {
                        ans[i] = -1;
                    }
                }
                total_time = max - d;
                int change = max;
                // cout << total_time << " " << change << " " << endl;
                for (int i = 0; i < n; i++)
                {
                    if (max > ans[i] && ans[i] != -1)
                    {
                        max = ans[i];
                    }
                }
                total_time += change - max;
                change = max;
                // cout << total_time << " " << change << " " << endl;
                for (int i = 0; i < n; i++)
                {
                    if (max < ans[i] && ans[i] != -1)
                    {
                        max = ans[i];
                    }
                }
                total_time += max - change;
                change = max;
                // cout << total_time << " " << change << " " << endl;
            }
        }
    }        

    return 0;
}
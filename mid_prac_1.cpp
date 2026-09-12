#include <iostream>
#include <string>
using namespace std;

int main()
{
    int id[15];
    string task[15];
    bool completed[15];

    int count = 0;
    int nextId = 1;
    int choice;
    int taskId;
    bool found;

    cout << "\n===== To-Do List =====";
    while (true)
    {
        cout << "\n1. Add Task";
        cout << "\n2. Mark Task as Completed";
        cout << "\n3. View Pending Tasks";
        cout << "\n4. View Completed Tasks";
        cout << "\n5. Delete a Task";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                if (count == 15)
                {
                    cout << "Task limit reached";
                    break;
                }

                cout << "Enter task: ";
                cin.ignore();
                getline(cin, task[count]);

                id[count] = nextId;
                completed[count] = false;

                cout << "Task added with ID: " << nextId;

                count++;
                nextId++;
                break;


            case 2:
                cout << "Enter task ID: ";
                cin >> taskId;

                found = false;

                for (int i = 0; i < count; i++)
                {
                    if (id[i] == taskId)
                    {
                        found = true;

                        if (completed[i])
                        {
                            cout << "Task is already completed";
                        }
                        else
                        {
                            completed[i] = true;
                            cout << "Task completed";
                        }

                        break;
                    }
                }

                if (!found)
                {
                    cout << "Task not found";
                }

                break;


            case 3:
                found = false;

                for (int i = 0; i < count; i++)
                {
                    if (!completed[i])
                    {
                        cout << id[i] << ". " << task[i] << endl;
                        found = true;
                    }
                }

                if (!found)
                {
                    cout << "No tasks to show";
                }

                break;


            case 4:
                found = false;

                for (int i = 0; i < count; i++)
                {
                    if (completed[i])
                    {
                        cout << id[i] << ". " << task[i] << endl;
                        found = true;
                    }
                }

                if (!found)
                {
                    cout << "No tasks to show";
                }

                break;


            case 5:
                cout << "Enter task ID: ";
                cin >> taskId;

                found = false;

                for (int i = 0; i < count; i++)
                {
                    if (id[i] == taskId)
                    {
                        found = true;

                        for (int j = i; j < count - 1; j++)
                        {
                            id[j] = id[j + 1];  //high index to low index and copying tasks from next to previous indexes
                            task[j] = task[j + 1];
                            completed[j] = completed[j + 1];
                        }

                        count--;

                        cout << "Task deleted";
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Task not found";
                }

                break;


            case 6:
                cout << "Exiting...";
                return 0;


            default:
                cout << "Invalid choice";
        }
    }

    return 0;
}


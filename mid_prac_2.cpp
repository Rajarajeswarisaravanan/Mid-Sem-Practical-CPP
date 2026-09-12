#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string name[20];
    string phone[20];

    int count = 0;
    int ch;
    string searchName;
    string phnNo;
    bool found;

    while (true)
    {
        cout << "\n1. Add Contact";
        cout << "\n2. View All Contacts";
        cout << "\n3. Search Contact by Name";
        cout << "\n4. Delete Contact by Name";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                if (count == 20)
                {
                    cout << "Contact book is full";
                    break;
                }

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name[count]);

                found = false;

                // Check whether the name already exists
                for (int i = 0; i < count; i++)
                {
                    string a = name[i];
                    string b = name[count];

                    for (int j = 0; j < a.length(); j++)
                    {
                        a[j] = tolower(a[j]);
                    }

                    for (int j = 0; j < b.length(); j++)
                    {
                        b[j] = tolower(b[j]);
                    }

                    if (a == b)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    cout << "Contact already exists";
                    break;
                }

                cout << "Enter 10-digit phone number: ";
                cin >> phnNo;

                if (phnNo.length() != 10)
                {
                    cout << "Invalid phone number";
                    break;
                }

                phone[count] = phnNo;

                count++;

                cout << "Contact added";
                break;


            case 2:
                if (count == 0)
                {
                    cout << "No contacts to show";
                    break;
                }

                for (int i = 0; i < count; i++)
                {
                    cout << "\nName: " << name[i];
                    cout << "\nPhone: " << phone[i] << endl;
                }

                break;


            case 3:
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, searchName);

                found = false;

                for (int i = 0; i < count; i++)
                {
                    string a = name[i];
                    string b = searchName;

                    for (int j = 0; j < a.length(); j++)
                    {
                        a[j] = tolower(a[j]);
                    }

                    for (int j = 0; j < b.length(); j++)
                    {
                        b[j] = tolower(b[j]);
                    }

                    if (a == b)
                    {
                        cout << "Name: " << name[i];
                        cout << "\nPhone: " << phone[i];

                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Contact not found";
                }

                break;


            case 4:
                cout << "Enter name to delete: ";
                cin.ignore();
                getline(cin, searchName);

                found = false;

                for (int i = 0; i < count; i++)
                {
                    string a = name[i];
                    string b = searchName;

                    for (int j = 0; j < a.length(); j++)
                    {
                        a[j] = tolower(a[j]);
                    }

                    for (int j = 0; j < b.length(); j++)
                    {
                        b[j] = tolower(b[j]);
                    }

                    if (a == b)
                    {
                        found = true;

                        // Shift contacts one position to the left
                        for (int j = i; j < count - 1; j++)
                        {
                            name[j] = name[j + 1];
                            phone[j] = phone[j + 1];
                        }

                        count--;

                        cout << "Contact deleted";
                        break;
                    }
                }

                if (!found)
                {
                    cout << "Contact not found";
                }

                break;


            case 5:
                cout << "Exiting...";
                return 0;


            default:
                cout << "Invalid choice";
        }
    }

    return 0;
}

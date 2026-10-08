#include <iostream>
#include<queue>
using namespace std;
int main(){
queue<string> que;
string patient;
int ch;

 do
    {
        cout<< "\n 1. Add Patient";
        cout<< "\n 2. Call Patient";
        cout<< "\n 3. Display Patients";
        cout<< "\n 4. Exit";
        cout<< "\n Enter choice: ";
        cin>> ch;

        if(ch==1)
        {
            cout<< "Enter Patient Name: ";
            cin>> patient;
            cout<<"Patient Added";
            que.push(patient);
        }
        else if(ch==2)
        {
            if(que.empty())
                cout<< "No More Patients for Today";
            else
            {
                cout<<"Calling a Patient: " << que.front();
                cout<<"\n Patient Got Discharged";
                que.pop();
            }
        }
        else if(ch==3)
        {
            if(que.empty())
                cout<< "No More Patients for Today";
            else
                cout<< "Next patient in a Waiting List: " << que.front();
        }

    } while(ch!=4);

    return 0;
}

#include <iostream>
using namespace std;
class Student
{
public:
string name;
int regno;

Student(string n, int r)
{
name = n;
regno = r;
}

void display()
{
cout << "Buddy: " << name << endl;
cout << "Identity: " << regno << endl;
}
};

int main()
{
Student stu1("Raji", 143);
Student stu2("Tamil selvi", 160);

stu1.display();
stu2.display();
return 0;
}

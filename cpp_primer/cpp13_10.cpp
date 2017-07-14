// set up to constructors: a default one, and the other one with a string (employee's name) as parameter

#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    string name;
    int id;
    static int counter; // use this to generate unique id for each employee
public:
    // default constructor
    Employee(): name("NoName"), id(counter)
    {
        ++counter;
    }  
    Employee(string nm): name(nm), id(counter)
    {
        ++counter;
    }
    // NOTE: here do not copy other's id => that's why we should use a copy constructor to implement this unique functionality
    Employee(const Employee& other): name(other.name), id(counter)
    {
        ++counter;
    }
    // assignment operator
    //NOTE here we do not assign id, because id has already be created by default constructor when this new object is defined
    Employee& operator=(const Employee& rhe)
    {
        name = rhe.name;  
        return *this;
    }
};
//assume employees' id start from 1
int Employee::counter = 1;

int main()
{
    Employee e1("yum");
    Employee e2("kong");
    Employee e3;
    e3 = e2;
    cout << "Employee id, Employee name " << endl;
    cout << e1.id << ", " << e1.name << endl;
    cout << e2.id << ", " << e2.name << endl;
    cout << e3.id << ", " << e3.name << endl;
    return 0;
}

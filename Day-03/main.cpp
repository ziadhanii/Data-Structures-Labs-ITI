#include <iostream>
#include <string>
using namespace std;

class Employee
{

public:
    int id;
    string name;
    int age;
    double salary;

    Employee()
    {
        id = 0;
        name = "";
        age = 0;
        salary = 0.0;
    }

    Employee(int _id, string _name, int _age, double _salary)
    {
        id = _id;
        name = _name;
        age = _age;
        salary = _salary;
    }

    void Display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
        cout << "--------------------" << endl;
    }
};

class Node
{
public:
    Employee data;
    Node* next;
    Node* prev;

    Node(Employee e)
    {
        data = e;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
public:
    Node* head;
    Node* tail;

    DoublyLinkedList()
    {
        head = tail = nullptr;
    }

    void addEmployee(Employee emp)
    {
        Node* newNode = new Node(emp);

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void DisplayAll()
    {
        Node* temp = head;
        while (temp)
        {
            temp->data.Display();
            temp = temp->next;
        }
    }

    void deleteAll()
    {
        Node* temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    ~DoublyLinkedList()
    {
        deleteAll();
    }
};

class StackDLL : public DoublyLinkedList
{
public:
    void Push(Employee emp)
    {
        Node* pNew = new Node(emp);

        pNew->next = head;
        pNew->prev = nullptr;

        if (head)
        {
            head->prev = pNew;
            head = pNew;
        }
        else
        {
            head = tail = pNew;
        }
    }


    void Pop()
    {
        if (!head)
            return;

        Node* pNode = head;

        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }

        pNode->next = pNode->prev = nullptr;
        delete pNode;
    }

    Node* Peek()
    {
        if (!head)
        {
            cout << "Stack is empty." << endl;
            return nullptr;
        }

        cout << "Top Employee in Stack:" << endl;
        head->data.Display();
        return head;
    }

    Employee* SearchStackById(int id)
    {
        Node* temp = head;

        while (temp)
        {
            if (temp->data.id == id)
                return &temp->data;

            temp = temp->next;
        }
        return nullptr;
    }

    void freeStack()
    {
        while (head)
            Pop();
    }

    void DisplayAll()
    {
        if (!head)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Employees in Stack:" << endl;
        DoublyLinkedList::DisplayAll();
    }
};

int main()
{
    StackDLL stack;

    stack.Push(Employee(1, "Ziad", 25, 5000));
    stack.Push(Employee(2, "Nour", 30, 7000));
    stack.Push(Employee(3, "Hany", 28, 6000));
    cout << "\n******************** \n";


    cout << "\n Top Of Stack :\n";
    stack.Peek();

    cout << "\n******************** \n";

    cout << "\n Display All\n";
    stack.DisplayAll();
    cout << "\n******************** \n";


    cout << "\nAfter Pop:\n";
    stack.Pop();
    stack.DisplayAll();


    stack.freeStack();
    cout << "\nDisplay  After Free Stack\n";
    stack.DisplayAll();
    cout << "\n******************** \n";

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}

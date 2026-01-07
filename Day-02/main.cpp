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

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }
    return -1;
}

int binarySearchOnEmployees(Employee arr[], int size, int targetId)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid].id == targetId)
            return mid;
        else if (arr[mid].id < targetId)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void sortByIdWithBubbleSort(Employee arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j].id > arr[j + 1].id)
                swap(arr[j], arr[j + 1]);
}

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
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
    }

    void addEmployee(Employee emp)
    {
        Node* newNode = new Node(Employee(emp.id, emp.name, emp.age, emp.salary));

        //  if (!head)
        if (head == nullptr)
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

    void insertAtBeginning(Employee emp)
    {
        Node* newNode = new Node(Employee(emp.id, emp.name, emp.age, emp.salary));

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtMiddle(int position, Employee emp)
    {
        if (position <= 0)
        {
            insertAtBeginning(emp);
            return;
        }

        Node* newNode = new Node(Employee(emp.id, emp.name, emp.age, emp.salary));
        Node* temp = head;

        for (int i = 0; i < position - 1 && temp; i++)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next)
                temp->next->prev = newNode;

            temp->next = newNode;

            if (newNode->next == nullptr)
                tail = newNode;
        }
    }

    void deleteById(int id)
    {
        Node* temp = head;

        while (temp)
        {
            if (temp->data.id == id)
            {
                if (temp->prev)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;

                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    void deleteAtPosition(int position)
    {
        if (position < 0)
            return;

        Node* temp = head;

        for (int i = 0; i < position && temp; i++)
        {
            temp = temp->next;
        }

        if (!temp)
            return;

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        delete temp;
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

    void deleteFromBeginning()
    {
        if (!head)
            return;

        Node* temp = head;
        head = head->next;

        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
    }

    void deleteFromEnd()
    {
        if (!tail)
            return;

        Node* temp = tail;
        tail = tail->prev;

        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
    }


    void sortEmployeeDoublyLinkedListByIdWithBubbleSort()
    {
        if (!head || !head->next)
            return;

        bool swapped;
        Node* current;
        Node* last = nullptr;

        do
        {
            swapped = false;
            current = head;

            while (current->next != last)
            {
                if (current->data.id > current->next->data.id)
                {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        }
        while (swapped);
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

    ~DoublyLinkedList()
    {
        deleteAll();
    }
};


int main()
{
    Employee employees[] = {
        {1, "Ahmed", 22, 5000},
        {2, "Sara", 25, 6000},
        {3, "Ali", 30, 7000},
        {4, "Mona", 28, 6500}
    };

    sortByIdWithBubbleSort(employees, 4);

    int size = 4;
    int idToSearch = 3;
    int index = binarySearchOnEmployees(employees, size, idToSearch);

    if (index != -1)
    {
        cout << "Found" << endl;
        employees[index].Display();
    }
    else
        cout << "Employee not found\n";


    DoublyLinkedList list;

    Employee bebo = Employee(5, "Beboo", 22, 5000);
    Employee hamada = Employee(4, "Hamada", 27, 5500);
    Employee ziad = Employee(3, "Ziad", 30, 7000);
    Employee nour = Employee(2, "Nour", 28, 6500);
    Employee omar = Employee(1, "Omar", 25, 6000);


    list.addEmployee(ziad); // end
    list.addEmployee(nour); // end
    list.insertAtBeginning(bebo); // beginning
    list.insertAtMiddle(3, omar); // middle
    list.insertAtMiddle(2, hamada); // middle


    cout << "\nBefore sorting DLL:\n";
    list.DisplayAll();

    // Bonus
    list.sortEmployeeDoublyLinkedListByIdWithBubbleSort();

    cout << "\nAfter sorting DLL:\n";
    list.DisplayAll();


    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}

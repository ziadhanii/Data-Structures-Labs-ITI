#include <iostream>
#include <algorithm>
using namespace std;

static string DESC_Order = "DESC";
static string ASC_Order = "ASC";

static string SORT_BY_ID = "ID";
static string SORT_BY_SALARY = "SALARY";

class Employee
{
    int id;
    string name;
    float salary;

public:

    int getId() { return id; }
    string getName() { return name; }
    float getSalary() { return salary; }


    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    void setSalary(float s) { salary = s; }

    Employee()
    {
    }

    Employee(int i, string n, float s)
    {
        id = i;
        name = n;
        salary = s;
    }

    void print()
    {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }
};

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) // O(n) → outer loop runs (n - 1) times ==> n
    {
        int key = arr[i]; // O(1)
        int j = i - 1; // O(1)

        while (j >= 0 && arr[j] > key) // O(n) → in worst case, shifts up to n elements
        {
            arr[j + 1] = arr[j]; // O(1)
            j--; // O(1)
        }

        arr[j + 1] = key; // O(1)
    } // Total Time Complexity: O(n^2)
}

void insertionSortOnEmployeesById(Employee emp[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Employee key = emp[i];
        int j = i - 1;

        while (j >= 0 && emp[j].getId() > key.getId())
        {
            emp[j + 1] = emp[j];
            j--;
        }
        emp[j + 1] = key;
    }
}

void insertionSortOnEmployeesBySalary(Employee emp[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Employee key = emp[i];
        int j = i - 1;

        while (j >= 0 && emp[j].getSalary() > key.getSalary())
        {
            emp[j + 1] = emp[j];
            j--;
        }
        emp[j + 1] = key;
    }
}

void insertionSortOnEmployees(Employee emp[], int n, string sortBy, string order)
{
    for (int i = 1; i < n; i++)
    {
        Employee key = emp[i];
        int j = i - 1;

        while (j >= 0)
        {
            bool condition = false;

            if (sortBy == SORT_BY_ID)
            {
                if (order == ASC_Order)
                    condition = emp[j].getId() > key.getId();

                else if (order == DESC_Order)
                    condition = emp[j].getId() < key.getId();
            }

            else if (sortBy == SORT_BY_SALARY)
            {
                if (order == ASC_Order)
                    condition = emp[j].getSalary() > key.getSalary();

                else if (order == DESC_Order)
                    condition = emp[j].getSalary() < key.getSalary();
            }

            if (!condition)
                break;

            emp[j + 1] = emp[j];
            j--;
        }

        emp[j + 1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])minIndex = j;


        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = false;
            }
        }
        if (swapped) break;
    }
}

int main()
{
    Employee emp[5] = {
        Employee(2, "Ahmed", 5000),
        Employee(1, "Nour", 6000),
        Employee(4, "Ali", 4500),
        Employee(5, "Omar", 7000),
        Employee(3, "Ziad", 5500)
    };
    insertionSortOnEmployeesById(emp, 5);

    for (int i = 0; i < 5; i++)
        emp[i].print();


    int arr[] = {9, -1, 0, 2};
    int n = 4;

    selectionSort(arr, n);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    int i = 1; // O(1)
    int sum = 0; // O(1)

    while (i <= n) // O(n+1) → outer loop runs n times
    {
        int j = 1; // O(n)

        while (j <= n) // O(n(n+1)) → inner loop runs n times for each i
        {
            sum = sum + i; // O (n(n))
            j = j + 1; // O n(n)
        }

        i = i + 1; // O(n)

    } // Total Time Complexity: O(n^2)


    insertionSortOnEmployees(emp, 5, SORT_BY_SALARY, DESC_Order);
    cout << "\nSorted Employees by ID in ASC order:\n";
    for (int i = 0; i < 5; i++)
        emp[i].print();


    return 0;
}

# Data Structures Labs - ITI

This repository contains lab exercises and implementations for Data Structures course at ITI.

## Project Structure

```
.
├── Day-01/          # Day 1 lab exercises
├── Day-02/          # Day 2 lab exercises
├── Day-03/          # Day 3 lab exercises
└── ...              # Additional days will be added
```

## Prerequisites

- C++ compiler (GCC, Clang, or MSVC)
- CMake 3.0 or higher
- CLion IDE (optional, but recommended)

## Building and Running

Each day's exercises are organized in separate directories with their own CMake configuration.

### Building a specific day

```bash
cd Day-01
mkdir -p cmake-build-debug
cd cmake-build-debug
cmake ..
cmake --build .
```

### Running the executable

After building:

```bash
./Day_01  # On Linux/macOS
# or
Day_01.exe  # On Windows
```

Or if using CLion, simply open the project and use the built-in build and run configuration.

## Topics Covered

### Day 01: Sorting Algorithms

- **Insertion Sort**: Basic implementation and time complexity analysis (O(n²))
- **Selection Sort**: Implementation with array swapping
- **Bubble Sort**: Optimized version with early termination
- **Custom Sorting**: Sorting Employee objects by ID and Salary
- **Flexible Sorting**: Generic sorting function with ASC/DESC order options
- Algorithm complexity analysis and optimization techniques

### Day 02: Searching & Doubly Linked Lists

- **Binary Search**: Implementation on arrays and Employee objects
- **Doubly Linked List**: Complete implementation with Node structure
- **List Operations**:
  - Insert (beginning, middle, end)
  - Delete (by ID, by position, from beginning, from end)
  - Search and display operations
- **Sorting Linked Lists**: Bubble sort implementation for doubly linked lists
- Integration of sorting with binary search for efficient data retrieval

### Day 03: Stack Implementation Using Doubly Linked List

- **Stack ADT**: Implementation using inheritance from Doubly Linked List
- **Stack Operations**:
  - Push: Add employee to top of stack
  - Pop: Remove employee from top of stack
  - Peek: View top element without removal
- **Advanced Stack Features**:
  - Search by ID within the stack
  - Free/Clear entire stack
  - Display all stack elements
- Practical implementation of LIFO (Last-In-First-Out) principle

---

More topics to be added...

## Author

- **Repository Owner**: ziadhanii

## License

This project is for educational purposes as part of ITI training program.

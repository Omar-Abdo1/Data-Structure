# C++ Data Structures Template

This project provides a collection of fundamental data structures implemented in C++. It includes implementations for AVL Trees, Heaps, Binary Search Trees, Linked Lists, Queues, and Stacks. The project is designed to be a template for learning and experimentation with these data structures.

## Data Structures Included

- **AVL Tree**: A self-balancing binary search tree that maintains its height to ensure O(log n) time complexity for insertion, deletion, and search operations.
- **Heap**: Implements both MaxHeap and MinHeap, allowing for efficient priority queue operations.
- **Binary Search Tree (BST)**: A classic data structure that supports dynamic set operations such as insertion, deletion, and search.
- **Doubly Linked List**: A flexible data structure that allows for efficient insertion and deletion of nodes.
- **Queue**: A first-in-first-out (FIFO) data structure implemented using a linked list.
- **Stack**: A last-in-first-out (LIFO) data structure implemented using a linked list.

## Project Structure

```
cpp-data-structures-template
├── include
│   ├── AVL_TREE.h
│   ├── Heap.h
│   ├── ITIBST.h
│   ├── ITI-LinkedList.h
│   ├── Queue.h
│   └── Stack.h
├── src
│   └── main.cpp
├── CMakeLists.txt
├── README.md
└── .gitignore
```

## Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/cpp-data-structures-template.git
   cd cpp-data-structures-template
   ```

2. **Build the Project**:
   Make sure you have CMake installed. Then run:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the Application**:
   After building, you can run the application:
   ```bash
   ./your_executable_name
   ```

## Usage Examples

- **AVL Tree**: Use the `AVL_TREE` class to create an AVL tree, insert elements, and perform searches.
- **Heap**: Use `MaxHeap` or `MinHeap` to manage a collection of elements with priority.
- **Queue**: Use the `Queue` class to manage tasks in a FIFO manner.
- **Stack**: Use the `Stack` class to manage tasks in a LIFO manner.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any enhancements or bug fixes.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
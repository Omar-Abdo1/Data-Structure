#include <iostream>
#include "AVL_TREE.h"
#include "Heap.h"
#include "ITIBST.h"
#include "ITI-LinkedList.h"
#include "Queue.h"
#include "Stack.h"

int main() {
    std::cout << "Welcome to the C++ Data Structures Template!" << std::endl;

    // Example usage of AVL Tree
    AVL_TREE<int> avlTree;
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    std::cout << "AVL Tree InOrder: ";
    avlTree.printInOrder();

    // Example usage of MaxHeap
    MaxHeap<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);
    std::cout << "MaxHeap Peek: " << maxHeap.peek() << std::endl;

    // Example usage of MinHeap
    MinHeap<int>minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);
    std::cout << "MinHeap Peek: " << minHeap.peek() << std::endl;

    // Example usage of Binary Search Tree
    ITIBST<int> bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(15);
    std::cout << "BST InOrder: ";
    bst.inOrder();

    // Example usage of LinkedList
    LinkedList linkedList;
    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);
    std::cout << "LinkedList: ";
    linkedList.Display();

    // Example usage of Queue
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    std::cout << "Queue Front: " << queue.front() << std::endl;
    queue.dequeue();

    // Example usage of Stack
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    std::cout << "Stack Top: " << stack.peek() << std::endl;
    stack.pop();

    return 0;
}
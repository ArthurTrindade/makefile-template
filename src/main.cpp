#include <iostream>
#include <memory>
#include <ostream>

#include "../include/functions.hpp"

namespace List {

// Define the Node class for singly linked list
template <typename T> struct Node {
  T data;
  std::shared_ptr<Node<T>> next;

  Node(const T &value) : data(value), next(nullptr) {}
};

// Define the SinglyLinkedList class
template <typename T> class SinglyLinkedList {
private:
  std::shared_ptr<Node<T>> head;

public:
  SinglyLinkedList() : head(nullptr) {}

  // Insert a new node at the beginning of the list
  void insert(const T &value) {
    auto newNode = std::make_shared<Node<T>>(value);
    newNode->next = head;
    head = newNode;
  }

  // Display the elements in the list
  void display() {
    auto current = head;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};

// Define the Node class for doubly linked list
template <typename T> struct DNode {
  T data;
  std::shared_ptr<DNode<T>> prev;
  std::shared_ptr<DNode<T>> next;

  DNode(const T &value) : data(value), prev(nullptr), next(nullptr) {}
};

// Define the DoublyLinkedList class
template <typename T> class DoublyLinkedList {
private:
  std::shared_ptr<DNode<T>> head;
  std::shared_ptr<DNode<T>> tail;

public:
  DoublyLinkedList() : head(nullptr), tail(nullptr) {}

  // Insert a new node at the end of the list
  void insert(const T &value) {
    auto newNode = std::make_shared<DNode<T>>(value);
    if (!head) {
      head = tail = newNode;
    } else {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }
  }

  // Display the elements in the list forward
  void displayForward() {
    auto current = head;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

  // Display the elements in the list backward
  void displayBackward() {
    auto current = tail;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->prev;
    }
    std::cout << std::endl;
  }
};
} // namespace List

int main() {
  List::SinglyLinkedList<int> singlyList;
  singlyList.insert(5);
  singlyList.insert(10);
  singlyList.insert(15);

  List::DoublyLinkedList<double> doublyList;
  doublyList.insert(3.14);
  doublyList.insert(2.718);
  doublyList.insert(1.618);

  std::cout << "Singly Linked List: ";
  singlyList.display();

  std::cout << "Doubly Linked List (Forward): ";
  doublyList.displayForward();

  std::cout << "Doubly Linked List (Backward): ";
  doublyList.displayBackward();

  std::cout << "Soma: 10 + 10 " << add(10, 10) << std::endl;
  return 0;
}

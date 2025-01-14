// Melissa Ochoa FLores
// COMSC 210
// Midterm 1

#include <iostream>
using namespace std;


struct Node {
    int data; 
    Node* prev; // Pointer to the previous node in the list
    Node* next; // Pointer to the next node in the list

    // Constructor to initialize the node with a value and optional pointers to previous and next nodes
    Node(int val, Node* p = nullptr, Node* n = nullptr) {
        data = val;
        prev = p;
        next = n;
    }
};

// Doubly linked list class to manage nodes
class DoublyLinkedList {
private:
    Node* head; // Points to the first node
    Node* tail; // Points to the last node

public:
    //  initializes an empty doubly linked list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int v) {
        // Create a new node with the given value
        Node* newNode = new Node(v);
        if (!tail) {
            
            head = tail = newNode;
        }
        else {
            // Link the new node at the end of the list
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;  // Update the tail pointer to the new node
        }
    }
    void push_front(int v) {
        // Create a new node with the provided value
        Node* newNode = new Node(v);
        if (!head) {
            
            head = tail = newNode;
        }
        else {
            
            newNode->next = head;
            head->prev = newNode;
            head = newNode;  // Update head to point to the new node
        }
    }
    void print() {
        Node* current = head;  // Start from the head node
        if (!current) {
            cout << "List is empty." << endl;  // Handle empty list case
            return;
        }

        // print each node's data
        while (current) {
            cout << current->data << " ";  // Print the data of the current node
            current = current->next;  // Move to the next node
        }
        cout << endl;  
    }

    void delete_val(int value) {
        if (!head) return;  // Return if the list is empty

        Node* temp = head;  // Start from the head of the list
        while (temp && temp->data != value) {
            temp = temp->next;  
        }

        if (!temp) return;

        if (temp->prev) {
            temp->prev->next = temp->next;  
        }
        else {
            head = temp->next;  // Update head if the first node is deleted
        }
        

        if (temp->next) {
            temp->next->prev = temp->prev;  
        }
        else {
            tail = temp->prev;  // Update tail if the last node is deleted
        }
        

        delete temp;  
    }

    void every_other_element() {
        Node* current = head;  // Start from the head node
        bool print = true; //decides to print or not

       while(current) {
            if (print) {
                cout << current->data << " ";  // Print every other element
            }
            print = !print;  
            current = current->next;  
        }
        cout << endl; 
    }
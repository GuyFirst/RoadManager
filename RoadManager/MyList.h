#pragma once
// Node structure for the linked list
struct Node {
    float data;
    Node* next;

    Node(float value) : data(value), next(nullptr) {}
};

class MyList {
private:
    Node* head;      // Head of the list
public:
    MyList() : head(nullptr) {};                          // Constructor to initialize the list
    ~MyList();                                           // Destructor to free the list
    void append(float value);                              // Append a value to the list
    void prepend(float value);                             // Prepend a value to the list              
    void print() const;                                  // print the list
    bool isEmpty() const { return head == nullptr; };    // Check if the list is empty


};


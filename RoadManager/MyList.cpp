#include "MyList.h"
#include <iostream>
#include <iomanip>  // For std::fixed and std::setprecision

MyList::MyList(const MyList& other) : head(nullptr) {

    Node* current = other.head;
    while (current != nullptr) {
        append(current->data);
        current = current->next;
    }
}
// Destructor to free memory allocated for the list
MyList::~MyList() {clear();}

// Append a value to the end of the list
void MyList::append(float value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Prepend a value to the beginning of the list
void MyList::prepend(float value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Delete the first occurrence of a value

// Display the list

void MyList::print() const {
    Node* current = head;
    while (current != nullptr) {
        // Print the data with 4 digits after the decimal point
        std::cout << std::fixed << std::setprecision(4) << current->data;
        current = current->next;
		if (current != nullptr) {std::cout << ", ";}
    }
	std::cout << std::endl;
}

void MyList::clear()
{
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    
}

MyList& MyList::operator=(const MyList & other) {
    // Check for self-assignment
    if (this == &other) {
        return *this;  
    }

    clear();

    
    Node* current = other.head;
    while (current != nullptr) {
        append(current->data); // Append data from the other list
        current = current->next;
    }
    return *this;  
}

#include "Heap.h"
#include <algorithm>
#include "RoadManager.h"
#include <iostream>

// Constructor: allocate memory for the heap and make the heap empty.
Heap::Heap(int roadNumber)
{
    data = new Road[roadNumber];
    maxSize = roadNumber;
    heapSize = roadNumber;
    allocated = 1;
}

// Destructor: delete memory only if allocated by heap.
Heap::~Heap()
{
    if (allocated) {
        delete[] data;
    }
    data = nullptr;
}

Road Heap::Max()
{
        return data[0];  // Root of the heap 
}

// Private Member functions of Heap class
int Heap::Parent(int node)
{
    return (node - 1) / 2;
}

int Heap::Left(int node)
{
    return (2 * node + 1);
}

int Heap::Right(int node)
{
    return (2 * node + 2);
}


void Heap::FixHeap(int node) // Fixes the heap that has node
{
    int max;
    int left = Left(node);
    int right = Right(node);


    if (left < heapSize) {

        if (((data[left].priority_minBridgeHeight > data[node].priority_minBridgeHeight) ||      //left node has higher priority
            (data[left].priority_minBridgeHeight == data[node].priority_minBridgeHeight &&
                data[left].subPriority_numOfBridges < data[node].subPriority_numOfBridges)) &&  //left node has equal priority but higher subpriority
            data[left].haveBridges) {                                                       //left have bridges
            max = left;
        }
        else { max = node; }
    }
    else { max = node; }

    if (right < heapSize) {

        if (((data[right].priority_minBridgeHeight > data[max].priority_minBridgeHeight) ||       //right node has higher priority
            (data[right].priority_minBridgeHeight == data[max].priority_minBridgeHeight &&
                data[right].subPriority_numOfBridges < data[max].subPriority_numOfBridges)) &&  //right node has equal priority but higher subpriority
            data[right].haveBridges) { 					                                  //right have bridges
            max = right;
        }
    }


    // Swap values if necessary, and continue fixing the heap towards the leaves.
    if (max != node) {
		std::swap(data[node], data[max]);
		FixHeap(max);
    }
}

void Heap::print() const
{
	std::cout << "the max: " << this->data[0].roadNumber << std::endl;
    for (int i = 0; i < heapSize; i++) {
        std::cout << "roadnumber: " << data[i].roadNumber << " minBridgeHeight: " << data[i].priority_minBridgeHeight << " subPrority numOfbridges: " << data[i].subPriority_numOfBridges << std::endl;
    }
}




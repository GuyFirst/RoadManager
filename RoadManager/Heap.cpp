#include "Heap.h"
#include <algorithm>
#include "RoadManager.h"


// Constructor: allocate memory for the heap and make the heap empty.
Heap::Heap(int roadNumber)
{
    data = new Road[roadNumber];
    maxSize = roadNumber;
    heapSize = 0;
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


void Heap::FixHeap(int node) // Fixes the heap that has node as root.
{
    int max;
    int left = Left(node);
    int right = Right(node);

	Road dataTemp;

    if (left < heapSize) {

        if (((data[left].priority_minRoadHeight > data[node].priority_minRoadHeight) ||      //left node has higher priority
            (data[left].priority_minRoadHeight == data[node].priority_minRoadHeight &&
                data[left].subPriority_numOfBridges < data[node].subPriority_numOfBridges)) &&  //left node has equal priority but higher subpriority
            data[left].haveBridges) {                                                       //left have bridges
            max = left;
        }
        else { max = node; }
    }
    else { max = node; }

    if (right < heapSize) {

        if (((data[right].priority_minRoadHeight > data[max].priority_minRoadHeight) ||       //right node has higher priority
            (data[right].priority_minRoadHeight == data[max].priority_minRoadHeight &&
                data[right].subPriority_numOfBridges < data[max].subPriority_numOfBridges)) &&  //right node has equal priority but higher subpriority
            data[right].haveBridges) { 					                                  //right have bridges
            max = right;
        }
    }


    // Swap values if necessary, and continue fixing the heap towards the leaves.
    if (max != node) {
	    dataTemp = data[node];
		data[node] = data[max];
		data[max] = dataTemp;
        FixHeap(max);
    }
}





void Heap::Update(int node) {
    int left = Left(node);
    int right = Right(node);
    int parent = Parent(node);

    Road dataTemp;
    // Check if the parent index is valid
    if (parent >= 0) {
        while (parent >= 0) {
            // Check if the node has a higher priority or equal priority but higher subpriority
            if (((data[node].priority_minRoadHeight > data[parent].priority_minRoadHeight) ||
                (data[node].priority_minRoadHeight == data[parent].priority_minRoadHeight &&
                    data[node].subPriority_numOfBridges < data[parent].subPriority_numOfBridges)) &&
                data[parent].haveBridges) {
                dataTemp = data[node];
                data[node] = data[parent];
                data[parent] = dataTemp;          // Swap the nodes
                node = parent;                    // Move up the heap (update node to parent)
                parent = Parent(node);            // Recalculate parent
            }
            else {
                break;  // Exit the loop if the heap property is satisfied
            }
        }
    }
    else {
		// If the parent priority is higher, fix the heap from the node downwards.
        FixHeap(node);
    }
}


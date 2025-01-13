#include "RoadManager.h"  
#include "Heap.h"          
#include "MyList.h" 


RoadManager::RoadManager(int roadNumber) : heapRoads(roadNumber), numOfRoads(numOfRoads)
{
    arrRoads = new Road[roadNumber];
    for (int i = 0; i < roadNumber; i++) {
        arrRoads[i].roadNumber = heapRoads.data[i].roadNumber = i+1;
		arrRoads[i].priority_minBridgeHeight = heapRoads.data[i].priority_minBridgeHeight = 0;
		arrRoads[i].subPriority_numOfBridges = heapRoads.data[i].subPriority_numOfBridges = 0;
		arrRoads[i].haveBridges = heapRoads.data[i].haveBridges = false;
        arrRoads[i].bridges = MyList();
    }
    // Set the bidirectional pointer: each road in arrRoads will point back to the corresponding road in heapRoads
    for (int i = 0; i < roadNumber; i++) {
        arrRoads[i].pRoad = &heapRoads.data[i];
        heapRoads.data[i].pRoad = &arrRoads[i];
    }
}


void RoadManager::AddBridge(float h, int r)
{
    //incremant bridge number
    arrRoads[r].bridges.append(h);
    arrRoads[r].pRoad->subPriority_numOfBridges++;
    arrRoads[r].subPriority_numOfBridges++;

	//update the heap
    if (!arrRoads[r].haveBridges) { //the first bridge
		arrRoads[r].pRoad->haveBridges = arrRoads[r].haveBridges = true;
		arrRoads[r].pRoad->priority_minBridgeHeight = arrRoads[r].priority_minBridgeHeight = h;
		heapRoads.FixHeap(r);
    }
	else if (h < arrRoads[r].priority_minBridgeHeight) { //new bridge is lower than the current min
        arrRoads[r].pRoad->priority_minBridgeHeight = arrRoads[r].priority_minBridgeHeight = h;
		heapRoads.FixHeap(r);
	}
    heapRoads.print();
}

int RoadManager::WhichRoad(float height) {  return (heapRoads.Max().priority_minBridgeHeight > height) ? (heapRoads.Max()).roadNumber + 1 : 0;}

// Copy constructor
Road::Road(const Road& other) {
    roadNumber = other.roadNumber;
    priority_minBridgeHeight = other.priority_minBridgeHeight;
    subPriority_numOfBridges = other.subPriority_numOfBridges;
    haveBridges = other.haveBridges;

    
    bridges = other.bridges;  // MyList has its own copy constructor
    // Copy the pRoad pointer, deep copy if necessary
   pRoad = other.pRoad ? new Road(*other.pRoad) : nullptr;  // Create a new Road object or set to nullptr if pRoad is nullptr
}

// Assignment operator
Road& Road::operator=(const Road& other) {
    if (this == &other) {
        return *this;  // Self-assignment, return the same object
    }

    roadNumber = other.roadNumber;
    priority_minBridgeHeight = other.priority_minBridgeHeight;
    subPriority_numOfBridges = other.subPriority_numOfBridges;
    haveBridges = other.haveBridges;

    
    bridges = other.bridges;  // MyList has its own assignment operator

   
    if (other.pRoad) {
        if (pRoad) {
            delete pRoad;  
        }
        pRoad = new Road(*other.pRoad);  // Create a new Road object
    }
    else {
        pRoad = nullptr;  // Set to nullptr if the other object has nullptr for pRoad
    }

    return *this;  // Return *this to allow chaining of assignment
}


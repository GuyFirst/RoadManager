#include "RoadManager.h"  
#include "Heap.h"          
#include "MyList.h" 


RoadManager::RoadManager(int roadNumber) : heapRoads(roadNumber), roadNumber(roadNumber)
{
    arrRoads = new Road[roadNumber];
    for (int i = 0; i < roadNumber; i++) {
        arrRoads[i].roadNumber = heapRoads.data[i].roadNumber = i+1;
		arrRoads[i].priority_minRoadHeight = heapRoads.data[i].priority_minRoadHeight = 0;
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
		arrRoads[r].pRoad->priority_minRoadHeight = arrRoads[r].priority_minRoadHeight = h;
		heapRoads.FixHeap(r);
    }
	else if (h < arrRoads[r].priority_minRoadHeight) { //new bridge is lower than the current min
        arrRoads[r].pRoad->priority_minRoadHeight = arrRoads[r].priority_minRoadHeight = h;
		heapRoads.FixHeap(r);
	}
    
}

int RoadManager::WhichRoad(float height) {  return (heapRoads.Max().priority_minRoadHeight > height) ? (heapRoads.Max()).roadNumber + 1 : 0;}



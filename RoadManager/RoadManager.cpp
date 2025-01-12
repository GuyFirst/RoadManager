#include "RoadManager.h"  
#include "Heap.h"          
#include "MyList.h" 


RoadManager::RoadManager(int roadNumber) : heapRoads(roadNumber)
{
    arrRoads = new Road[roadNumber];
    for (int i = 0; i < roadNumber; i++)
		arrRoads[i].bridges = MyList();

    // Set the bidirectional pointer: each road in arrRoads will point back to the corresponding road in heapRoads
    for (int i = 0; i < roadNumber; i++) {
        arrRoads[i].pRoad = &heapRoads.data[i];
        heapRoads.data[i].pRoad = &arrRoads[i];
    }
}


void RoadManager::AddBridge(float h, int r)
{
    arrRoads[r].haveBridges = true;
    arrRoads[r].bridges.append(h);
    if (!arrRoads[r].haveBridges) {
		arrRoads[r].pRoad->haveBridges = arrRoads[r].haveBridges = true;
		arrRoads[r].pRoad->priority_minRoadHeight = arrRoads[r].priority_minRoadHeight = h;
		arrRoads[r].pRoad->subPriority_numOfBridges++;
		arrRoads[r].subPriority_numOfBridges++;
		heapRoads.Update(r);
    }
    else if (h < arrRoads[r].priority_minRoadHeight) {
        arrRoads[r].priority_minRoadHeight = h;
		heapRoads.Update(r);
    }
}

int RoadManager::WhichRoad(float height) { return (heapRoads.Max()).roadNumber; }



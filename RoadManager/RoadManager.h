#pragma once
#include "Heap.h"
#include "MyList.h"

struct Road  // Define Road consistently as a struct
{
    unsigned int roadNumber = 0;
    float priority_minRoadHeight = 0;            // Sort by maximum
    unsigned int subPriority_numOfBridges = 0;  // If needed, sort by minimum
    MyList bridges;                            // List of bridges
    bool haveBridges = false;
    Road* pRoad = nullptr;

};

class RoadManager
{
    Heap heapRoads;
    Road* arrRoads; // Array of Roads
	int roadNumber;
public:
    RoadManager(int roadNumber); // Constructor
    ~RoadManager() { delete[] arrRoads; }            // Destructor
    void AddBridge(float h, int r);
    int WhichRoad(float height);
    void Print(int r) const { arrRoads[r].bridges.print(); }
};
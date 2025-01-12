#pragma once

struct Road;

class Heap {
private:
    int maxSize;
    int heapSize;
    int allocated;
    static int Left(int node);
    static int Right(int node);
    static int Parent(int node);
    void FixHeap(int node);

public:
    Road* data; // Points to data array
    Heap(int max); // Constructor for allocating memory
    ~Heap();
    Road Max();
	void Update( int node);
};

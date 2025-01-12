#include <iostream>
#include "Heap.h"
#include "RoadManager.h"
#include "MyList.h"

int main() {
    int m, n;
    std::cin >> m;  // number of roads
    std::cin >> n;  // number of operation
	RoadManager roadSystem(m);

    for (int i = 0; i < n; ++i) {
        char op;
        std::cin >> op;

        if (op == 'a') {
            ;
        }
        else if (op == 'b') {
            float h;
            int r;
            std::cin >> h >> r;
			roadSystem.AddBridge(h, r);
        }
        else if (op == 'c') {
            float height;
            std::cin >> height;
            int result = roadSystem.WhichRoad(height);
            std::cout << result << std::endl;
        }
        else if (op == 'd') {
            int r;
            std::cin >> r;
			roadSystem.Print(r);
        }
    }

    return 0;
}
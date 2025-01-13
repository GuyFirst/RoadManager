#include <iostream>
#include "Heap.h"
#include "RoadManager.h"
#include "MyList.h"

int main() {
    int m, n;
    std::cin >> m;  // number of roads
    std::cin >> n;  // number of operation
    if(m < 0 || n < 0)
	{
		std::cout << "invalid input" << std::endl;
		return 0;
	}
	RoadManager roadSystem(m);
	bool a = false;
    for (int i = 0; i < n; ++i) {
        char op;
        std::cin >> op;

        if (op == 'a') {
           a = true ;
        }
        else if (op == 'b') {
            float h;
            int r;
            std::cin >> h >> r;
			if (r >= 1 && r <= m && h > 0 && a)
			      roadSystem.AddBridge(h, r-1);
            else {
                std::cout << "invalid input" << std::endl;
                return 0;
            }
        }
        else if (op == 'c') {
			if (m == 0)
			{
				std::cout << "0" << std::endl;
				continue;
			}
            else {
                float height;
                std::cin >> height;
                int result = roadSystem.WhichRoad(height);
                std::cout << result << std::endl;
            }
        }
        else if (op == 'd') {
            int r;
            std::cin >> r;
			if (r > 1 && r <= m)
			  roadSystem.Print(r-1);
        }
    }

    return 0;
}
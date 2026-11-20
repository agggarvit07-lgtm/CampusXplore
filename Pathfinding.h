#ifndef PATHFINDING_H
#define PATHFINDING_H

#include "Graph.h"
#include <string>
#include <vector>

struct PathResult {
    bool found = false;
    int totalDistance = 0;
    std::vector<int> path;   // location ids from start to destination
};

class Pathfinding {
public:
    // requiredType = "" means normal shortest route.
    // requiredType = "Stairs" or "Elevator" means the route must use that
    // type and must avoid the other one.
    static PathResult shortestPath(const Graph& graph, int source,
                                   int destination,
                                   const std::string& requiredType = "");
};

#endif

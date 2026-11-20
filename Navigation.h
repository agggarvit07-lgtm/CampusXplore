#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "Graph.h"
#include "Pathfinding.h"
#include <string>

class Navigation {
private:
    const Graph& graph;

public:
    explicit Navigation(const Graph& graph);

    void showRoute(int source, int destination,
                   const std::string& requiredType = "") const;
    void findEmergencyExit(int source) const;
    void displayIdentifiedLocation(int locationId) const;
};

#endif

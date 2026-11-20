#ifndef GRAPH_H
#define GRAPH_H

#include "Location.h"
#include <string>
#include <vector>

// One direction of a road, stored in a location's neighbour list.
struct Edge {
    int destination;
    int distance;
    int connectionId;
};

// One road between two locations (can be blocked or restored).
struct Connection {
    int source;
    int destination;
    int distance;
    bool blocked;
};

class Graph {
private:
    std::vector<Location> locations;
    std::vector<std::vector<Edge>> adjacencyList;  // neighbours of each location
    std::vector<Connection> connections;

    // Removes spaces at both ends and converts to lowercase.
    std::string normalize(const std::string& text) const;

public:
    Graph();

    void addConnection(int source, int destination, int distance);
    int searchLocation(const std::string& name) const;
    int searchQR(const std::string& code) const;

    void displayLocations() const;
    void displayConnections() const;
    bool changeConnectionStatus(int id, bool block);

    bool isType(int index, const std::string& requiredType) const;
    const std::vector<Location>& getLocations() const;
    const std::vector<Edge>& getEdges(int index) const;
    const std::vector<Connection>& getConnections() const;
    bool isConnectionBlocked(int connectionId) const;
};

#endif

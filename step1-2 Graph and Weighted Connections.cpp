
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Location {
private:
    int id;
    string name;
    string type;
    int floor;

public:
    Location(int id, string name, string type, int floor) {
        this->id = id;
        this->name = name;
        this->type = type;
        this->floor = floor;
    }

    void display() const {
        cout << id << " | " << name << " | "
             << type << " | Floor " << floor << '\n';
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getType() const { return type; }
    int getFloor() const { return floor; }
};

struct Edge {
    int destination;
    int distance;
};

class Graph {
private:
    vector<Location> locations;
    vector<vector<Edge>> adjacencyList;

public:
    void addLocation(Location location) {
        locations.push_back(location);
        adjacencyList.push_back(vector<Edge>());
    }

    void addConnection(int source, int destination, int distance) {
        if (source < 0 || destination < 0 ||
            source >= (int)locations.size() ||
            destination >= (int)locations.size() ||
            distance < 0) {
            cout << "Invalid connection ignored.\n";
            return;
        }

        adjacencyList[source].push_back({destination, distance});
        adjacencyList[destination].push_back({source, distance});
    }

    void displayLocations() const {
        for (const Location& location : locations) {
            location.display();
        }
    }

    void displayConnections() const {
        for (int i = 0; i < (int)locations.size(); i++) {
            cout << locations[i].getName() << " -> ";

            for (const Edge& edge : adjacencyList[i]) {
                cout << locations[edge.destination].getName()
                     << " (" << edge.distance << "m) ";
            }

            cout << '\n';
        }
    }
};

int main() {
    Graph campus;

    campus.addLocation(Location(0, "Main Gate", "Entrance", 0));
    campus.addLocation(Location(1, "Admin Block", "Office", 0));
    campus.addLocation(Location(2, "Library", "Library", 1));

    campus.addConnection(0, 1, 50);
    campus.addConnection(1, 2, 40);
    campus.addConnection(0, 2, 80);

    campus.displayLocations();
    campus.displayConnections();

    return 0;
}

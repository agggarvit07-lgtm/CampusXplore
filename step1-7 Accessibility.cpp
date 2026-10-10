
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <algorithm>
#include <cctype>

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
        cout << id << " | " << name
             << " | " << type
             << " | Floor " << floor << '\n';
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

    bool isStairs(int locationIndex) const {
        return locations[locationIndex].getType() == "Stairs";
    }

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
        cout << "\n===== CAMPUS LOCATIONS =====\n";

        for (const Location& location : locations) {
            location.display();
        }
    }

    void displayLocationNames() const {
        cout << "\nAvailable locations:\n";

        for (const Location& location : locations) {
            cout << location.getId() << ". "
                 << location.getName()
                 << " (Floor " << location.getFloor() << ")\n";
        }
    }

    void displayConnections() const {
        cout << "\n===== CAMPUS CONNECTIONS =====\n";

        for (int i = 0; i < (int)locations.size(); i++) {
            cout << locations[i].getName() << " -> ";

            for (const Edge& edge : adjacencyList[i]) {
                cout << locations[edge.destination].getName()
                     << " (" << edge.distance << "m)  ";
            }

            cout << '\n';
        }
    }

    int searchLocation(string name) const {
        transform(name.begin(), name.end(), name.begin(),
                  [](unsigned char c) {
                      return (char)tolower(c);
                  });

        for (int i = 0; i < (int)locations.size(); i++) {
            string locationName = locations[i].getName();

            transform(locationName.begin(), locationName.end(),
                      locationName.begin(),
                      [](unsigned char c) {
                          return (char)tolower(c);
                      });

            if (locationName == name) {
                return i;
            }
        }

        return -1;
    }

    void dijkstra(int source, int destination, bool avoidStairs) const {
        int n = (int)locations.size();

        if (source < 0 || destination < 0 ||
            source >= n || destination >= n) {
            cout << "Invalid source or destination.\n";
            return;
        }

        vector<int> distance(n, INT_MAX);
        vector<int> parent(n, -1);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        distance[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            if (currentDistance > distance[currentNode]) {
                continue;
            }

            for (const Edge& edge : adjacencyList[currentNode]) {
                int nextNode = edge.destination;

                if (avoidStairs &&
                    (isStairs(currentNode) || isStairs(nextNode))) {
                    continue;
                }

                int newDistance = currentDistance + edge.distance;

                if (newDistance < distance[nextNode]) {
                    distance[nextNode] = newDistance;
                    parent[nextNode] = currentNode;
                    pq.push({newDistance, nextNode});
                }
            }
        }

        if (distance[destination] == INT_MAX) {
            cout << "\nNo route available with the selected preference.\n";
            return;
        }

        vector<int> path;

        for (int current = destination; current != -1;
             current = parent[current]) {
            path.push_back(current);
        }

        reverse(path.begin(), path.end());

        cout << "\nShortest distance: "
             << distance[destination] << " meters\n";

        cout << "Route: ";

        for (int i = 0; i < (int)path.size(); i++) {
            cout << locations[path[i]].getName();

            if (i + 1 < (int)path.size()) {
                cout << " -> ";
            }
        }

        cout << '\n';
    }
};

int main() {
    Graph campus;

    campus.addLocation(Location(0, "Main Gate", "Entrance", 0));
    campus.addLocation(Location(1, "Admin Block", "Office", 0));
    campus.addLocation(Location(2, "Computer Lab 1", "Laboratory", 1));
    campus.addLocation(Location(3, "Computer Lab 2", "Laboratory", 1));
    campus.addLocation(Location(4, "CSE Department", "Department", 2));
    campus.addLocation(Location(5, "Library", "Library", 1));
    campus.addLocation(Location(6, "Mechanical Lab", "Laboratory", 0));
    campus.addLocation(Location(7, "Seminar Hall", "Hall", 2));
    campus.addLocation(Location(8, "Cafeteria", "Food", 0));
    campus.addLocation(Location(9, "Emergency Exit", "Emergency", 0));

    campus.addLocation(Location(10, "Stairs Ground", "Stairs", 0));
    campus.addLocation(Location(11, "Stairs First", "Stairs", 1));
    campus.addLocation(Location(12, "Stairs Second", "Stairs", 2));
    campus.addLocation(Location(13, "Elevator Ground", "Elevator", 0));
    campus.addLocation(Location(14, "Elevator First", "Elevator", 1));
    campus.addLocation(Location(15, "Elevator Second", "Elevator", 2));

    campus.addConnection(0, 1, 50);
    campus.addConnection(0, 8, 80);
    campus.addConnection(1, 5, 40);
    campus.addConnection(1, 6, 60);
    campus.addConnection(5, 2, 30);
    campus.addConnection(5, 3, 40);
    campus.addConnection(2, 3, 20);
    campus.addConnection(2, 4, 50);
    campus.addConnection(4, 7, 30);
    campus.addConnection(6, 9, 40);
    campus.addConnection(8, 9, 70);

    campus.addConnection(10, 11, 15);
    campus.addConnection(11, 12, 15);
    campus.addConnection(13, 14, 5);
    campus.addConnection(14, 15, 5);

    campus.addConnection(0, 10, 20);
    campus.addConnection(2, 11, 10);
    campus.addConnection(4, 12, 10);
    campus.addConnection(0, 13, 20);
    campus.addConnection(2, 14, 10);
    campus.addConnection(4, 15, 10);

    campus.displayLocationNames();

    string sourceName, destinationName;

    cout << "\nEnter your current location exactly as listed: ";
    getline(cin >> ws, sourceName);

    cout << "Enter your destination exactly as listed: ";
    getline(cin >> ws, destinationName);

    int source = campus.searchLocation(sourceName);
    int destination = campus.searchLocation(destinationName);

    if (source == -1 || destination == -1) {
        cout << "\nLocation not found. Check the spelling and try again.\n";
        return 0;
    }

    char accessibleChoice;

    cout << "\nAvoid stairs and use an elevator route where possible? (y/n): ";
    cin >> accessibleChoice;

    bool avoidStairs =
        (accessibleChoice == 'y' || accessibleChoice == 'Y');

    campus.dijkstra(source, destination, avoidStairs);

    return 0;
}

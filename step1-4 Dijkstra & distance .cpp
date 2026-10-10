
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
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
        cout << "\nAvailable locations:\n";

        for (const Location& location : locations) {
            cout << location.getId() << ". "
                 << location.getName()
                 << " (Floor " << location.getFloor() << ")\n";
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

    void dijkstra(int source, int destination) const {
        int n = (int)locations.size();

        vector<int> distance(n, INT_MAX);

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
                int newDistance = currentDistance + edge.distance;

                if (newDistance < distance[nextNode]) {
                    distance[nextNode] = newDistance;
                    pq.push({newDistance, nextNode});
                }
            }
        }

        if (distance[destination] == INT_MAX) {
            cout << "No route available.\n";
            return;
        }

        cout << "\nShortest distance: "
             << distance[destination] << " meters\n";
    }
};

int main() {
    Graph campus;

    campus.addLocation(Location(0, "Main Gate", "Entrance", 0));
    campus.addLocation(Location(1, "Admin Block", "Office", 0));
    campus.addLocation(Location(2, "Library", "Library", 1));
    campus.addLocation(Location(3, "Computer Lab 1", "Laboratory", 1));

    campus.addConnection(0, 1, 50);
    campus.addConnection(1, 2, 40);
    campus.addConnection(0, 2, 80);
    campus.addConnection(2, 3, 30);

    campus.displayLocations();

    string sourceName, destinationName;

    cout << "\nEnter your current location: ";
    getline(cin >> ws, sourceName);

    cout << "Enter your destination: ";
    getline(cin >> ws, destinationName);

    int source = campus.searchLocation(sourceName);
    int destination = campus.searchLocation(destinationName);

    if (source == -1 || destination == -1) {
        cout << "Location not found.\n";
        return 0;
    }

    campus.dijkstra(source, destination);

    return 0;
}

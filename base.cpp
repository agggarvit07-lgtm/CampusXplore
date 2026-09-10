  #include <iostream>
#include <vector>
#include <string>

using namespace std;

class Location {
private:
    int Id;
    string Name;
    string Type;
    int Floor;

public:
    Location(int id, string name, string type, int floor) {
        Id = id;
        Name = name;
        Type = type;
        Floor = floor;
    }

    void display() {
        cout << "ID: " << Id
             << " | " << Name
             << " | Type: " << Type
             << " | Floor: " << Floor << endl;
    }

    int getId() {
        return Id;
    }

    string getName() {
        return Name;
    }

    string getType() {
        return Type;
    }

    int getFloor() {
        return Floor;
    }
};

class Graph {
private:
    vector<Location> Locations;

public:
    void addLocation(Location location) {
        Locations.push_back(location);
    }

    void displayLocations() {
        cout << "\nCAMPUS LOCATIONS\n";

        for (int i = 0; i < Locations.size(); i++) {
            Locations[i].display();
        }
    }
};

int main() {
    Graph Campus;

    Campus.addLocation(Location(1, "Main Gate", "Entrance", 0));
    Campus.addLocation(Location(2, "BTech Block", "Block", 0));
    Campus.addLocation(Location(3, "Library", "Library", 1));
    Campus.addLocation(Location(4, "Param Lab", "Laboratory", 1));
    Campus.addLocation(Location(5, "Aryabhatta Lab", "Laboratory", 1));
    Campus.addLocation(Location(6, "Chanakya Block", "Block", 0));
    Campus.addLocation(Location(7, "Civil Block", "Block", 0));
    Campus.addLocation(Location(8, "Mechanical Block", "Block", 0));
    Campus.addLocation(Location(9, "Electrical Block", "Block", 0));
    Campus.addLocation(Location(10, "Cafeteria", "Food", 0));

    Campus.displayLocations();

    return 0;
}

#include <iostream>
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

int main() {
    Location l1(0, "Main Gate", "Entrance", 0);
    Location l2(1, "Admin Block", "Office", 0);

    l1.display();
    l2.display();

    return 0;
}

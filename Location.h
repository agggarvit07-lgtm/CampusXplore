#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {
private:
    int id;
    std::string name;
    std::string type;
    int floor;
    std::string qrCode;

public:
    Location(int id, const std::string& name, const std::string& type,
             int floor, const std::string& qrCode);

    void display() const;

    int getId() const;
    const std::string& getName() const;
    const std::string& getType() const;
    int getFloor() const;
    const std::string& getQR() const;
};

#endif

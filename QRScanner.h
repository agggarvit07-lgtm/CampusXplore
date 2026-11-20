#ifndef QRSCANNER_H
#define QRSCANNER_H

#include <string>

class QRScanner {
public:
    // Temporary terminal input. Later, replace this implementation
    // with camera/scanner input while keeping the same interface.
    std::string readQRCode() const;
};

#endif

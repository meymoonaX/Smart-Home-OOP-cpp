#include <iostream>
using namespace std;

// Interface (Abstract Class)
class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
};

// Base class
class Device : public SmartDevice {
protected:
    bool isOn;
public:
    Device() { isOn = false; }

    void turnOn() {
        isOn = true;
    }

    void turnOff() {
        isOn = false;
    }
};

// Light class
class SmartLight : public Device {
public:
    void getStatus() {
        cout << (isOn ? "Light is ON" : "Light is OFF") << endl;
    }
};

// Fan class
class SmartFan : public Device {
public:
    void getStatus() {
        cout << (isOn ? "Fan is ON" : "Fan is OFF") << endl;
    }
};

// Camera class
class SmartCamera : public Device {
public:
    void getStatus() {
        cout << (isOn ? "Camera is ON" : "Camera is OFF") << endl;
    }
};

// Controller class
class HomeController {
public:
    void operateDevice(SmartDevice* device) {
        device->turnOn();
        device->getStatus();
    }
};

// Main function
int main() {
    SmartDevice* devices[3];

    devices[0] = new SmartLight();
    devices[1] = new SmartFan();
    devices[2] = new SmartCamera();

    for (int i = 0; i < 3; i++) {
        devices[i]->turnOn();
        devices[i]->getStatus();
    }

    HomeController hc;
    hc.operateDevice(new SmartLight());

    return 0;
}

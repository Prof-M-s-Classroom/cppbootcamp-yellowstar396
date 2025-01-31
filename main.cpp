#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the Robot class
class Robot {
private:
    string name;
    string model;
    int batteryLife;

public:
    // Constructor
    Robot(string n, string m, int bl) {
        this->name = n;
        this->model = m;
        this->batteryLife = bl;
    }

    // Getter Methods
    [[nodiscard]] string getName() const {
        return name;
    }

    [[nodiscard]] string getModel() const {
        return model;
    }

    [[nodiscard]] int getBatteryLife() const {
        return batteryLife;
    }

    // Setter Methods

    void set_name(const string &name) {
        this->name = name;
    }

    void set_model(const string &model) {
        this->model = model;
    }

    void set_battery_life(int battery_life) {
        batteryLife = battery_life;
    }

    // Display function
    void displayRobot() {
        cout << "Robot: " << name << " | Model: " << model << " | Battery Life: " << batteryLife << "%\n";
    }
};

// Step 2: Function to modify robot (pass by value)
void editRobotByVal(Robot robot, int val) {
    robot.set_battery_life(val);
}

// Step 3: Function to modify robot (pass by reference)
void editRobotByRef(Robot &robot, int val) {
    robot.set_battery_life(val);
}

// Step 4: Template class for a Fleet that stores multiple robots
template <typename T>
class Fleet {
private:
    T* robots;
    int capacity;
    int count;

public:
    // Constructor: Allocates space for 'capacity' robots
    Fleet(int cap) {
        capacity = cap;
        count = 0;
        robots = new T[capacity];
    }

    // Add robot to fleet
    void addRobot(T robot) {
        if (count < capacity) {
            robots[count] = robot;
            count++;
        } else {
            cout << "Fleet is full!\n";
        }
    }

    // Display all robots
    void showFleet() {
        cout << "Fleet contains:\n";
        for (int i = 0; i < count; i++) {
            cout << "- " << robots[i] << "\n";
        }
    }

    // Destructor: Free allocated memory
    ~Fleet() {
        delete[] robots;
    }
};

int main() {
    // Step 5: Create a Robot object
    Robot myRobot("Robot1", "RT500", 50);


    // Step 6: Use pointers to access Robot object
    Robot* robotPtr = &myRobot;
    cout << "Updated Battery Life (using pointer): " << robotPtr->getBatteryLife() << "%\n";

    // Step 7: Pass by value (no change outside function)
    editRobotByVal(myRobot, 10);
   cout << "After modifyRobotByValue, Battery Life: " << myRobot.getBatteryLife() << "%\n";

    // Step 8: Pass by reference (changes persist)
    editRobotByRef(myRobot, 20);
   cout << "After modifyRobotByReference, Battery Life: " << myRobot.getBatteryLife() << "%\n";

    // Step 9: Use the Fleet template class
    Fleet<string> myFleet(3);
    myFleet.addRobot("Autobot-X");
    myFleet.addRobot("Cybertron-7");
    myFleet.addRobot("NanoDroid-3");

    myFleet.showFleet();

    return 0;
}
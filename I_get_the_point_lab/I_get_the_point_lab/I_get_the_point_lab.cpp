#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x, y;

public:
    // Constructor
    Point(double x_coord = 0.0, double y_coord = 0.0) : x(x_coord), y(y_coord) {}

    // Method to get distance between two points
    double distance(const Point& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    // Overloading - operator to calculate distance
    double operator-(const Point& other) const {
        return distance(other);
    }

    // Overloading == operator for equality comparison
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    // Overloading != operator for inequality comparison
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    // Overloading / operator to find the midpoint between two points
    Point operator/(const Point& other) const {
        double mid_x = (x + other.x) / 2;
        double mid_y = (y + other.y) / 2;
        return Point(mid_x, mid_y);
    }

    // Overloading [] operator to access x or y coordinate, extra credit for portfolio 2
    double operator[](char coord) const {
        if (coord == 'x' || coord == 'X') {
            return x;
        }
        else if (coord == 'y' || coord == 'Y') {
            return y;
        }
        else {
            cerr << "Invalid coordinate: Use 'x' or 'y'" << endl;
            return 0; // Or throw an exception if preferred
        }
    }

    // Overloading << operator to print point
    friend ostream& operator<<(ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

int main() {
    
    Point p1(3.2, 9.8);
    Point p2(5.5, -1.2);
    
    cout << "Testing the operator- for distance: " << p1 - p2 << endl; // Expected output: 11.238

    cout << "Testing the operator== for equality:" << (p1 == p2) << endl; // Expected output: 0 (false)

    cout << "Testing the operator!= for inequality:" << (p1 != p2) << endl; // Expected output: 1 (true)

    cout << "Testing the operator/ for midpoint:" << p1 / p2 << endl; // Expected output: (4.35, 4.3)


    // Testing the [] operator to access x and y coordinates portfolio 2 extra credit 
    double my_x1 = p1['x'];
    double my_y1 = p1['y'];

    double my_x2 = p2['x'];
    double my_y2 = p2['y'];


    cout << "   Testing the operator[]   " << endl;
    cout << "Point1 x-coordinate: " << my_x1 << endl; // Expected output: 3.2
    cout << "Point1 y-coordinate: " << my_y1 << endl; // Expected output: 9.8

    cout << "Point2 x-coordinate: " << my_x2 << endl; // Expected output: 5.5
    cout << "Point2 y-coordinate: " << my_y2 << endl; //Expected output: -1.2
    return 0;
}

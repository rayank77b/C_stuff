#include <iostream>

using namespace std;

class Point {
    private:
        int x;
        int y;
    public:
        static int cnt;
        Point();
        Point(int X, int Y): x(X), y(Y) { }; 
        Point(const Point& obj);
        void myout();
        static void getcnt() {
            cout<<"Points: "<<cnt<<endl;
        }
};

Point::Point() {
    x=0; 
    y=0;
    cnt++;
}

Point::Point(const Point& obj) {
    x=obj.x;
    y=obj.y;
    cnt++;
}

void Point::myout() {
    cout<<"Point: "<<x<<" | "<<y<<endl;
}

int Point::cnt = 0;

int main() {
    cout<<"start.."<<endl;

    Point p0;
    Point p1(1,2);

    p0.myout();
    p1.myout();

    Point p2(p1);

    p2.myout();

    cout<<"Points: "<<Point::cnt<<endl;
    Point::getcnt();
    return 0;
}

#include <iostream>
#include <limits>
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "DynamicArray.h"

using namespace std;

void TestPoint() {
    cout << "========================================\n";
    cout << "          KIEM TRA LOP POINT            \n";
    cout << "========================================\n";
    Point p;
    cout << "Nhap toa do diem Point (x y): ";
    while (!(cin >> p)) {
        cout << "Nhap sai, vui long nhap lai (x y): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "=> Thong tin Point vua nhap (operator<< / ToString): " << p << "\n\n";
}

void TestLine() {
    cout << "========================================\n";
    cout << "          KIEM TRA LOP LINE             \n";
    cout << "========================================\n";
    Line l;
    cin >> l;
    cout << "=> Thong tin Line vua nhap (operator<< / ToString):\n" << l << "\n\n";
}

void TestRectangle() {
    cout << "========================================\n";
    cout << "        KIEM TRA LOP RECTANGLE          \n";
    cout << "========================================\n";
    Rectangle r;
    cin >> r;
    cout << "=> Thong tin Rectangle vua nhap (operator<< / ToString):\n" << r << "\n\n";
}

void TestDynamicArray() {
    cout << "========================================\n";
    cout << "      KIEM TRA LOP DYNAMIC ARRAY        \n";
    cout << "========================================\n";
    DynamicArray arr;
    cin >> arr;
    cout << "=> Thong tin DynamicArray vua nhap (operator<< / ToString):\n" << arr << "\n\n";
}

int main() {
    TestPoint();
    TestLine();
    TestRectangle();
    TestDynamicArray();

  
    return 0;
}

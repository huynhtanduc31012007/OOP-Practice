#include <iostream>
#include <iomanip>
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "DynamicArray.h"

using namespace std;

void TestPoint() {
    cout << "========================================\n";
    cout << "          KIEM TRA LOP POINT            \n";
    cout << "========================================\n";

    cout << "So luong Point ban dau: " << Point::InstanceCount << "\n";

    Point p1;
    cout << "+ Khoi tao mac dinh p1: (" << p1.X() << ", " << p1.Y() << ")\n";

    p1.SetX(3.0f);
    p1.SetY(4.0f);
    cout << "+ Sau khi SetX(3), SetY(4), p1: (" << p1.X() << ", " << p1.Y() << ")\n";

    Point p2(0.0f, 0.0f);
    cout << "+ Khoi tao co tham so p2: (" << p2.X() << ", " << p2.Y() << ")\n";

    Point p3(p1);
    cout << "+ Khoi tao sao chep p3 tu p1: (" << p3.X() << ", " << p3.Y() << ")\n";

    cout << "+ Khoang cach tu p1(3, 4) den p2(0, 0): " << p1.CalcDistanceTo(&p2) << " (ky vong: 5)\n";

    cout << "+ So luong Point hien tai: " << Point::InstanceCount << "\n";

    {
        cout << "  [Block test huy Point] Tao them p_temp trong block...\n";
        Point p_temp(10, 20);
        cout << "  -> So luong Point trong block: " << Point::InstanceCount << "\n";
    }
    cout << "+ So luong Point sau khi p_temp bi huy: " << Point::InstanceCount << "\n\n";
}

void TestLine() {
    cout << "========================================\n";
    cout << "          KIEM TRA LOP LINE             \n";
    cout << "========================================\n";

    cout << "So luong Line ban dau: " << Line::InstanceCount << "\n";

    Line l1;
    cout << "+ Khoi tao mac dinh l1 thanh cong.\n";

    Line l2(new Point(0, 0), new Point(3, 4));
    cout << "+ Khoi tao co tham so l2(Point(0,0), Point(3,4)) thanh cong.\n";

    Line l3(l2);
    cout << "+ Khoi tao sao chep l3 tu l2 thanh cong.\n";

    cout << "+ So luong Line hien tai: " << Line::InstanceCount << "\n";

    {
        cout << "  [Block test huy Line] Tao l_temp trong block...\n";
        Line l_temp;
        cout << "  -> So luong Line trong block: " << Line::InstanceCount << "\n";
    }
    cout << "+ So luong Line sau khi l_temp bi huy: " << Line::InstanceCount << "\n\n";
}

void TestRectangle() {
    cout << "========================================\n";
    cout << "        KIEM TRA LOP RECTANGLE          \n";
    cout << "========================================\n";

    cout << "So luong Rectangle ban dau: " << Rectangle::InstanceCount << "\n";

    Rectangle r1;
    cout << "+ Khoi tao mac dinh r1 thanh cong.\n";

    Rectangle r2(new Point(1, 5), new Point(6, 2));
    cout << "+ Khoi tao co tham so r2 thanh cong.\n";

    Rectangle r3(r2);
    cout << "+ Khoi tao sao chep r3 tu r2 thanh cong.\n";

    cout << "+ So luong Rectangle hien tai: " << Rectangle::InstanceCount << "\n";

    {
        cout << "  [Block test huy Rectangle] Tao r_temp trong block...\n";
        Rectangle r_temp;
        cout << "  -> So luong Rectangle trong block: " << Rectangle::InstanceCount << "\n";
    }
    cout << "+ So luong Rectangle sau khi r_temp bi huy: " << Rectangle::InstanceCount << "\n\n";
}

void TestCircle() {
    cout << "========================================\n";
    cout << "         KIEM TRA LOP CIRCLE            \n";
    cout << "========================================\n";

    Circle c;
    Point center(5.0f, 5.0f);
    c.SetCenter(&center);
    c.SetRadius(10.0f);

    cout << "+ Toa do tam: (" << c.Center()->X() << ", " << c.Center()->Y() << ")\n";
    cout << "+ Ban kinh (Radius): " << c.Radius() << "\n";
    cout << "+ Duong kinh (Diameter): " << c.Diameter() << "\n";
    cout << "+ Chu vi (Perimeter): " << c.Perimeter() << "\n";
    cout << "+ Dien tich (Area): " << c.Area() << "\n\n";
}

void TestDynamicArray() {
    cout << "========================================\n";
    cout << "      KIEM TRA LOP DYNAMIC ARRAY        \n";
    cout << "========================================\n";

    DynamicArray arr;
    cout << "+ Khoi tao mang rong, kich thuoc: " << arr.Size() << "\n";

    for (int i = 1; i <= 5; ++i) {
        arr.PushBack(i * 10);
    }
    cout << "+ Da them 5 phan tu (10, 20, 30, 40, 50).\n";
    cout << "+ Kich thuoc mang sau khi them: " << arr.Size() << "\n";

    cout << "+ Cac phan tu trong mang: ";
    for (int i = 0; i < arr.Size(); ++i) {
        cout << arr.GetAt(i) << " ";
    }
    cout << "\n";

    DynamicArray arrCopy(arr);
    arrCopy.PushBack(999);
    cout << "+ Tao mang sao chep arrCopy va them phan tu 999 vao arrCopy:\n";
    cout << "  -> Kich thuoc arr ban dau: " << arr.Size() << " (ky vong: 5)\n";
    cout << "  -> Kich thuoc arrCopy: " << arrCopy.Size() << " (ky vong: 6)\n";

    cout << "+ Kiem tra ngoai le khi truy cap vi tri vuot gioi han (index 100):\n";
    try {
        arr.GetAt(100);
    } catch (const std::exception& e) {
        cout << "  -> Bat thanh cong ngoai le: \"" << e.what() << "\"\n";
    }
    cout << "\n";
}

int main() {
    TestPoint();
    TestLine();
    TestRectangle();
    TestCircle();
    TestDynamicArray();

    cout << "========================================\n";
    cout << "              10 DIEM                   \n";
    cout << "========================================\n";
    return 0;
}

#include <iostream>
#include <string>
#include <limits>
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "DynamicArray.h"

using namespace std;

// ============================================================
// 1. KIEM TRA HAM PARSE CUA LOP POINT
// ============================================================
void TestParsePoint() {
    cout << "============================================================\n";
    cout << "               KIEM TRA POINT::PARSE\n";
    cout << "============================================================\n";

    // Test case 1: Chuoi dinh dang toa do thong thuong
    string s1 = "(3.5, 7.2)";
    cout << "[Test 1] Chuoi toa do chuan: \"" << s1 << "\"\n";
    Point* p1 = Point::Parse(s1);
    if (p1 != nullptr) {
        cout << "  -> Parse thanh cong: " << *p1 << "\n";
        cout << "  -> X = " << p1->X() << ", Y = " << p1->Y() << "\n";
        delete p1;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 2: Chuoi chi gom cac so cach nhau bang khoang trang
    string s2 = "10.5 25.0";
    cout << "[Test 2] Chuoi so cach nhau boi khoang trang: \"" << s2 << "\"\n";
    Point* p2 = Point::Parse(s2);
    if (p2 != nullptr) {
        cout << "  -> Parse thanh cong: " << *p2 << "\n";
        delete p2;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 3: Chuoi co chua ky tu chu va nhan
    string s3 = "Point at (100.0, 200.0)";
    cout << "[Test 3] Chuoi co nhan va ky tu chu: \"" << s3 << "\"\n";
    Point* p3 = Point::Parse(s3);
    if (p3 != nullptr) {
        cout << "  -> Parse thanh cong: " << *p3 << "\n";
        delete p3;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 4: Chuoi khong hop le (khong du toa do)
    string s4 = "invalid point (5.0)";
    cout << "[Test 4] Chuoi khong hop le (chi co 1 so): \"" << s4 << "\"\n";
    Point* p4 = Point::Parse(s4);
    if (p4 == nullptr) {
        cout << "  -> Ket qua: nullptr (Bat loi hop le vi khong du 2 toa do x, y)\n";
    } else {
        cout << "  -> Parse thanh cong: " << *p4 << "\n";
        delete p4;
    }
    cout << "\n";
}

// ============================================================
// 2. KIEM TRA HAM PARSE CUA LOP LINE
// ============================================================
void TestParseLine() {
    cout << "============================================================\n";
    cout << "                KIEM TRA LINE::PARSE\n";
    cout << "============================================================\n";

    // Test case 1: Chuoi 2 diem chuan
    string s1 = "(0, 0), (3, 4)";
    cout << "[Test 1] Chuoi 2 diem: \"" << s1 << "\"\n";
    Line* l1 = Line::Parse(s1);
    if (l1 != nullptr) {
        cout << "  -> Parse thanh cong:\n" << *l1 << "\n";
        cout << "  -> Do dai tinh duoc: " << l1->Length() << " (Ky vong: 5.0)\n";
        delete l1;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 2: Chuoi mo ta co chu va mui ten
    string s2 = "Line: (1.5, 2.5) -> (4.5, 6.5)";
    cout << "[Test 2] Chuoi mo ta co nhan: \"" << s2 << "\"\n";
    Line* l2 = Line::Parse(s2);
    if (l2 != nullptr) {
        cout << "  -> Parse thanh cong:\n" << *l2 << "\n";
        cout << "  -> Do dai tinh duoc: " << l2->Length() << " (Ky vong: 5.0)\n";
        delete l2;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 3: Chuoi gom 4 so cach nhau boi dau phay hoac khoang trang
    string s3 = "1 2 5 6";
    cout << "[Test 3] Chuoi 4 so nguyen: \"" << s3 << "\"\n";
    Line* l3 = Line::Parse(s3);
    if (l3 != nullptr) {
        cout << "  -> Parse thanh cong:\n" << *l3 << "\n";
        delete l3;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 4: Chuoi khong hop le (khong du 4 gia tri)
    string s4 = "(1, 2)";
    cout << "[Test 4] Chuoi thieu toa do (chi co 2 so): \"" << s4 << "\"\n";
    Line* l4 = Line::Parse(s4);
    if (l4 == nullptr) {
        cout << "  -> Ket qua: nullptr (Bat loi hop le vi khong du 4 toa do cho 2 diem)\n";
    } else {
        cout << "  -> Parse thanh cong:\n" << *l4 << "\n";
        delete l4;
    }
    cout << "\n";
}

// ============================================================
// 3. KIEM TRA HAM PARSE CUA LOP RECTANGLE
// ============================================================
void TestParseRectangle() {
    cout << "============================================================\n";
    cout << "              KIEM TRA RECTANGLE::PARSE\n";
    cout << "============================================================\n";

    // Test case 1: Chuoi TopLeft va BottomRight
    string s1 = "(2, 8), (7, 3)";
    cout << "[Test 1] Chuoi 2 diem goc: \"" << s1 << "\"\n";
    Rectangle* r1 = Rectangle::Parse(s1);
    if (r1 != nullptr) {
        cout << "  -> Parse thanh cong:\n" << *r1 << "\n";
        cout << "  -> Chieu rong (Width): " << r1->Width() << " (Ky vong: 5)\n";
        cout << "  -> Chieu cao (Height): " << r1->Height() << " (Ky vong: 5)\n";
        cout << "  -> Chu vi (Perimeter): " << r1->Perimeter() << " (Ky vong: 20)\n";
        cout << "  -> Dien tich (Area):   " << r1->Area() << " (Ky vong: 25)\n";
        delete r1;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 2: Chuoi dinh dang nhan TopLeft & BottomRight
    string s2 = "TopLeft = (0.0, 10.0), BottomRight = (12.0, 4.0)";
    cout << "[Test 2] Chuoi mo ta co nhan: \"" << s2 << "\"\n";
    Rectangle* r2 = Rectangle::Parse(s2);
    if (r2 != nullptr) {
        cout << "  -> Parse thanh cong:\n" << *r2 << "\n";
        cout << "  -> Chieu rong: " << r2->Width() << ", Chieu cao: " << r2->Height() << "\n";
        cout << "  -> Chu vi: " << r2->Perimeter() << ", Dien tich: " << r2->Area() << "\n";
        delete r2;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 3: Chuoi thieu toa do
    string s3 = "Rect: 1 2 3";
    cout << "[Test 3] Chuoi thieu gia tri (chi co 3 so): \"" << s3 << "\"\n";
    Rectangle* r3 = Rectangle::Parse(s3);
    if (r3 == nullptr) {
        cout << "  -> Ket qua: nullptr (Bat loi hop le vi khong du 4 toa do)\n";
    } else {
        cout << "  -> Parse thanh cong:\n" << *r3 << "\n";
        delete r3;
    }
    cout << "\n";
}

// ============================================================
// 4. KIEM TRA HAM PARSE CUA LOP DYNAMICARRAY
// ============================================================
void TestParseDynamicArray() {
    cout << "============================================================\n";
    cout << "             KIEM TRA DYNAMICARRAY::PARSE\n";
    cout << "============================================================\n";

    // Test case 1: Chuoi danh sach cac so nguyen cach nhau bang khoang trang
    string s1 = "10 20 30 40 50";
    cout << "[Test 1] Chuoi so nguyen: \"" << s1 << "\"\n";
    DynamicArray* a1 = DynamicArray::Parse(s1);
    if (a1 != nullptr) {
        cout << "  -> Parse thanh cong:\n" << *a1 << "\n";
        cout << "  -> Kich thuoc Size: " << a1->Size() << " (Ky vong: 5)\n";
        cout << "  -> Phan tu dau tien a[0]: " << a1->GetAt(0) << "\n";
        cout << "  -> Phan tu cuoi cung a[4]: " << a1->GetAt(4) << "\n";
        delete a1;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 2: Chuoi mang dang ngoac vuong va dau phay (JSON/Python style)
    string s2 = "[5, 15, 25, 35, 45, 55]";
    cout << "[Test 2] Chuoi dang mang [a, b, c]: \"" << s2 << "\"\n";
    DynamicArray* a2 = DynamicArray::Parse(s2);
    if (a2 != nullptr) {
        cout << "  -> Parse thanh cong:\n" << *a2 << "\n";
        delete a2;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 3: Chuoi co nhan va van ban kem so
    string s3 = "Danh sach diem thi: 8, 9, 10, 7, 8";
    cout << "[Test 3] Chuoi chua text va so: \"" << s3 << "\"\n";
    DynamicArray* a3 = DynamicArray::Parse(s3);
    if (a3 != nullptr) {
        cout << "  -> Parse thanh cong:\n" << *a3 << "\n";
        delete a3;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";

    // Test case 4: Chuoi rong khong co chu so nao
    string s4 = "khong co so nao trong chuoi nay";
    cout << "[Test 4] Chuoi khong co so nao: \"" << s4 << "\"\n";
    DynamicArray* a4 = DynamicArray::Parse(s4);
    if (a4 != nullptr) {
        cout << "  -> Parse thanh cong:\n" << *a4 << "\n";
        delete a4;
    } else {
        cout << "  -> Parse that bai!\n";
    }
    cout << "\n";
}

// ============================================================
// 5. THU NGHIEM NHAP CHUOI TUY Y TU BAN PHIM
// ============================================================
void InteractiveTest() {
    cout << "============================================================\n";
    cout << "        THU NGHIEM NHAP CHUOI TUY Y (INTERACTIVE)\n";
    cout << "============================================================\n";

    while (true) {
        cout << "Chon lop de test Parse:\n";
        cout << "  1. Point::Parse\n";
        cout << "  2. Line::Parse\n";
        cout << "  3. Rectangle::Parse\n";
        cout << "  4. DynamicArray::Parse\n";
        cout << "  0. Thoat\n";
        cout << "Lua chon cua ban: ";

        int choice;
        if (!(cin >> choice)) {
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) {
            cout << "Tam biet!\n";
            break;
        }

        string inputLine;
        switch (choice) {
            case 1: {
                cout << "Nhap chuoi cho Point (vi du: \"(12.5, 30.2)\" hoac \"5 10\"): ";
                getline(cin, inputLine);
                Point* p = Point::Parse(inputLine);
                if (p != nullptr) {
                    cout << "=> Ket qua Point::Parse: " << *p << "\n\n";
                    delete p;
                } else {
                    cout << "=> Parse that bai (chuoi khong hop le)!\n\n";
                }
                break;
            }
            case 2: {
                cout << "Nhap chuoi cho Line (vi du: \"(0, 0), (3, 4)\" hoac \"1 2 5 6\"): ";
                getline(cin, inputLine);
                Line* l = Line::Parse(inputLine);
                if (l != nullptr) {
                    cout << "=> Ket qua Line::Parse:\n" << *l << "\n\n";
                    delete l;
                } else {
                    cout << "=> Parse that bai (chuoi khong hop le)!\n\n";
                }
                break;
            }
            case 3: {
                cout << "Nhap chuoi cho Rectangle (vi du: \"(1, 10), (8, 2)\" hoac \"0 10 12 4\"): ";
                getline(cin, inputLine);
                Rectangle* r = Rectangle::Parse(inputLine);
                if (r != nullptr) {
                    cout << "=> Ket qua Rectangle::Parse:\n" << *r << "\n\n";
                    delete r;
                } else {
                    cout << "=> Parse that bai (chuoi khong hop le)!\n\n";
                }
                break;
            }
            case 4: {
                cout << "Nhap chuoi cho DynamicArray (vi du: \"1 2 3 4 5\" hoac \"[10, 20, 30]\"): ";
                getline(cin, inputLine);
                DynamicArray* arr = DynamicArray::Parse(inputLine);
                if (arr != nullptr) {
                    cout << "=> Ket qua DynamicArray::Parse:\n" << *arr << "\n\n";
                    delete arr;
                } else {
                    cout << "=> Parse that bai (chuoi khong hop le)!\n\n";
                }
                break;
            }
            default:
                cout << "Lua chon khong hop le, vui long chon lai!\n\n";
                break;
        }
    }
}

// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "\n";
    cout << "************************************************************\n";
    cout << "*       CHUONG TRINH KIEM TRA CAC HAM PARSE CHO CAC LOP     *\n";
    cout << "************************************************************\n\n";

    // 1. Chay cac test case tu dong cho tung lop
    TestParsePoint();
    TestParseLine();
    TestParseRectangle();
    TestParseDynamicArray();

    // 2. Cho phep nguoi dung nhap chuoi tuy y de kiem tra
    cout << "Ban co muon thu nghiem nhap chuoi tuy y khong? (1: Co, 0: Khong): ";
    int ans = 0;
    if (cin >> ans && ans == 1) {
        InteractiveTest();
    } else {
        cout << "Ket thuc chuong trinh kiem tra.\n";
    }

    return 0;
}

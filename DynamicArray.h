#ifndef DynamicArray_h
#define DynamicArray_h
#include <iostream>
#include <string> 
class DynamicArray{
private:
    int *m_data;
    int _len;
    int _capacity;
public:
    DynamicArray();
    DynamicArray(const DynamicArray&);
    ~DynamicArray();
    void PushBack(int value);
    int Size();
    int GetAt(int idx); 
    bool setSize(int n){
        if (n < 0)
            return false;
        _len = n;
        if (_len > 0)
            m_data = new int[_len];
        _capacity = _len;
        return true;        
    }
    std::string ToString();
    friend std::istream& operator >> (std::istream &is, DynamicArray &arr);
    friend std::ostream& operator << (std::ostream &os, const DynamicArray &arr);

}
;



#endif // DynamicArray_h

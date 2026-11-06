#ifndef DynamicArray_h
#define DynamicArray_h

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
};



#endif // DynamicArray_h

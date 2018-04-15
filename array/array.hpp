template <typename DataT>
class Array {
private:
    DataT* data_ = nullptr;
    size_t size_ = 0;
public:
    Array(void){}                                               ////  EXPLICIT ???
    Array(size_t size);
    Array(const Array& that);      // copy constructor
//    Array(Array&&that);           // move constructor
    ~Array(void);
    DataT& operator[](int pos);
    Array& operator=(Array that);
//    Array& operator=(Array&& that);
    void Swap(Array& that);
    void Print(void) const;
    void Dump(void) const;
};

enum ARRAY_EXC {
    WRONG_POS,
    DIFF_ARR_SIZE
};

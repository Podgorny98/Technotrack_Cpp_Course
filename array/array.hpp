#ifndef ARRAY_HPP
#define ARRAY_HPP
template <typename DataT>
class Array {
private:
    DataT* data_ = nullptr;
    size_t size_ = 0;
public:
    Array(void){}                                               ////  EXPLICIT ???
    Array(size_t size);
    Array(const Array& that);
//    Array(Array&&that);
    ~Array(void);
    DataT& operator[](int pos);
    Array& operator=(Array that);
//    Array& operator=(Array&& that);
    void Swap(Array& that);
    void Print(void) const;
    void Dump(void) const;
};
//=========================================================
template<>
class Array<bool> {
private:
    struct Proxy {
        uint8_t* byte_ = nullptr;
        int BitNum_ = 0;
        Proxy(void) {}
        Proxy(uint8_t* ArrayByte, int BitNum);
        ~Proxy(void);
        operator bool(void);
        void operator=(bool val);
    };
    uint8_t* data_ = nullptr;
    size_t size_ = 0;
    size_t BytesQt_ = 0;
public:
    Array(void){}
    Array(size_t size);
    Array(const Array& that);
    ~Array(void);
    Proxy operator[](int pos);
    Array& operator=(Array that);
    void Swap(Array& that);
    void Print(void) const;
    void Dump(void) const;
};
//=========================================================
enum ARRAY_EXC {
    WRONG_POS,
    DIFF_ARR_SIZE
};
#endif

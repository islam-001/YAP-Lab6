#include <array>
#include <iostream>

using namespace std;

bool IsHex(string str) {
    for(unsigned int i = 0; i < str.length(); i++) {
        if((str[i] > 'f') || (str[i] < '0') || ((str[i] > '9') && (str[i] < 'A')) || ((str[i] > 'F') && (str[i] < 'a')))
            return false;
    }
    return true;
}

template <size_t N> class superlong {
private:
    static constexpr size_t SIZE = N / 32 + (N % 32 != 0);
    array<uint32_t, N / 32 + (N % 32 != 0)> value;
    static string toHex(uint32_t u);
    string toHex();
public:
    superlong():value({}) {}
    superlong(const array<uint32_t, N / 32 + (N % 32 != 0)>& v):value(v) {}
    superlong(const string& s);
    superlong<N>& operator=(const superlong<N>& s);
    superlong<N> operator+(const superlong<N>& s) const;
    template <size_t X> 
    friend ostream& operator<< (ostream& stream, superlong<X>& s);
};

template <size_t N>
superlong<N>::superlong(const string& s) {
    try {
        if(IsHex(s) == false)
            throw invalid_argument("not HEX");
    } catch(const invalid_argument& ia) {
        cerr << "Invalid argument: " << ia.what() << '\n';
    }
    value = {0};
    int i = 0;
    auto ptr_2 = s.end();
    auto ptr_b = s.begin();
    while(ptr_b != ptr_2) {
        auto ptr_1 = ptr_2 - 8;
        if(ptr_1 < ptr_b)
            ptr_1 = ptr_b;
        value[i] = stoul(string(ptr_1, ptr_2), 0, 16);
        ptr_2 = ptr_1;
        i++;
    }
}

template <size_t N>
superlong<N>& superlong<N>::operator=(const superlong<N>& s) {
    value = s.value;
    return *this;
}

template <size_t N>
superlong<N> superlong<N>::operator+(const superlong<N>& s) const {
    superlong<N> sum;
    uint32_t CF = 0;
    for(size_t i = 0; i < SIZE; i++) {
        sum.value[i] = CF + value[i] + s.value[i];
        if(sum.value[i] < value[i])
            CF = 1;
        else
            CF = 0;
    }
    return sum;
}

template <size_t N>
string superlong<N>::toHex(uint32_t u) {
    const char d[] = "0123456789abcdef";
    string s;
    for(int i = 0; i < 8; i++) {
        s = d[u & 0xf] + s;
        u >>= 4;
    }
    return s;
}

template <size_t N>
string superlong<N>::toHex() {
    string s;
    for(auto e : value)
        s = superlong<N>::toHex(e) + s;
    return s;
}

template <size_t X>
ostream& operator << (ostream& stream, superlong<X>& s) {
    stream << s.toHex();
    return stream;
}

int main() {
    const size_t SZ = 512;
    superlong<SZ> num1;
    superlong<SZ> num2("bec0ffffffffffffffffffff0000ffff000fffffffffffffeeeeeeecccc");
    superlong<SZ> num3("399fa8873c0c737abcdef87837332178798883234fff878fed732233232");
    num1 = num3;
    num1 = num1 + num2;
    cout << num3 << endl;
    cout << num2 << endl;
    cout << num1 << endl;
    return 0;
}

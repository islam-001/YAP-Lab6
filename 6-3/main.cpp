#include <iostream>
#include <string>

using namespace std;

template<typename T1,typename T2>class DoubleBox {
private:
    T1 value;
    T2 value2;
public:
    void set(T1 x,T2 y) {
        value = x;
        value2 = y;
    }
    void get() {
        cout << "Первое значение: " << value << endl;
        cout << "Второе значение: " << value2 << endl;
    }
    DoubleBox (T1 value,T2 value2) {
        this->value= value;
        this->value2= value2;
    }
    DoubleBox () {
        this->value= 0;
        this->value2= 0;
    }
};

int main () {
    DoubleBox<int,double> type;
    type.set(35,14.94);
    type.get();
    return 0;
}

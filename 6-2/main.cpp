#include <iostream>

using namespace std;

template <typename T> class Rectangle {
    private:
        T width = T();
        T height = T();
    public:
        Rectangle() {
            width = 0;
            height = 0;
        }
        Rectangle(T _width, T _height) {
            width = _width;
            height = _height;
        }
        void input () {
            cout << "Введите значение ширины: ";
            cin >> width;
            cout << "Введите значение высоты: ";
            cin >> height;
            cout << endl;
        }
        T square () {
            T key = width * height;
            return key;
        }
        void sravn(Rectangle *mas, int size) {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size && j != i; j++) {
                    if (mas[i].square() > mas[j].square()) {
                        cout << "Площадь" << " = " << mas[i].square();
                        cout << " > " << "Площадь" << " = " << mas[j].square() << endl;
                    }
                    else if(mas[i].square() < mas[j].square()) {
                        cout << "Площадь" << " = " << mas[i].square();
                        cout << " < " << "Площадь" << " = " << mas[j].square() << endl;
                    }
                    else {
                        cout << "Площадь" << " = " << mas[i].square();
                        cout << " = " << "Площадь" << " = " << mas[j].square() << endl;
                    }
                }
            cout << endl;
        }
        void sort(Rectangle *mas, int size) {
            for (int i = 1; i < size; ++i)
                for (int j = size - 1; j >= i; --j)
                    if (mas[j - 1].square() > mas[j].square())
                        swap(mas[j], mas[j - 1]);
                for (int i = 0; i < size; i++)
                    cout << mas[i].square() << " ";
            cout << endl;
        }
};

int main() {
    int kolichestvo;
    cout << "Введите размер массива объектов класса: ";
    cin >> kolichestvo;
    cout << endl;
    Rectangle <int> sr;
    Rectangle <int> *mas = new Rectangle<int> [kolichestvo];
    for (int i = 0; i < kolichestvo; i++)
        mas[i].input();
    for (int i = 0; i < kolichestvo; i++)
        mas[i].square();
    sr.sravn(mas, kolichestvo);
    sr.sort(mas, kolichestvo);
    return 0;
}

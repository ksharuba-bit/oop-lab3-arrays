#include <iostream>
#include <iomanip>

using namespace std;

class TournamentArrayAnalyzer {
private:
    static const int SIZE = 6;
    double values[SIZE];

public:
    void read() {
        cout << "Введіть 6 елементів масиву: ";
        for (int i = 0; i < SIZE; ++i) {
            cin >> values[i];
        }
    }

    void print() const {
        cout << "Масив: ";
        for (int i = 0; i < SIZE; ++i) {
            cout << values[i] << " ";
        }
        cout << endl;
    }

    void findMinimum(double &minimum, int &position) const {
        minimum = values[0];
        position = 1;

        for (int i = 1; i < SIZE; ++i) {
            if (values[i] < minimum) {
                minimum = values[i];
                position = i + 1;
            }
        }
    }
};

int main() {
    TournamentArrayAnalyzer stats;
    stats.read();
    stats.print();

    double minimum;
    int position;
    stats.findMinimum(minimum, position);

    cout << fixed << setprecision(1);
    cout << "Мінімальний елемент: " << minimum << endl;
    cout << "Порядковий номер елемента: " << position << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

class TournamentMatrixAnalyzer {
private:
    static const int MAX_ROWS = 5;
    static const int MAX_COLS = 4;
    double matrix[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;

public:
    bool read() {
        cout << "Введіть кількість рядків (1..5): ";
        cin >> rows;
        cout << "Введіть кількість стовпців (1..4): ";
        cin >> cols;

        if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
            cout << "Некоректні розміри матриці." << endl;
            return false;
        }

        cout << "Введіть елементи матриці:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> matrix[i][j];
            }
        }
        return true;
    }

    void sortDescending() {
        double temp[MAX_ROWS * MAX_COLS];
        int count = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp[count++] = matrix[i][j];
            }
        }

        sort(temp, temp + count, greater<double>());

        count = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = temp[count++];
            }
        }
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    TournamentMatrixAnalyzer stats;

    if (!stats.read()) {
        return 1;
    }

    cout << "Початкова матриця:" << endl;
    stats.print();

    stats.sortDescending();

    cout << "Матриця після впорядкування за спаданням:" << endl;
    stats.print();

    return 0;
}

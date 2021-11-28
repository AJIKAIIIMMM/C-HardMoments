#include <iostream>
#include <list>
#include <numeric>
#include <iterator>
#include <vector>
#include <algorithm>


using namespace std;

class Matrix {
    vector<vector<double>> matrix;
    int n;
    double tmp, d;
public:
    Matrix() {
        cout << "Enter a matrix size:\n";
        cout << "n = ";
        cin >> n;
        cout << "Enter a matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
    };

    void determinant() {
        for (int k = 0; k < n - 1; k++) {
            for (int i = k + 1; i < n; i++) {
                tmp = -matrix[i][k] / matrix[k][k];
                for (int j = 0; j < n; j++) {
                    matrix[i][j] += matrix[k][j] * tmp;
                }
            }
        }
        cout << "\nTarget matrix:\n\n";
        cout.precision(2);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout.width(8);
                cout << fixed << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        d = 1;
        for (int i = 0; i < n; i++) {
            d *= matrix[i][i];
        }
        cout << fixed << "\nMatrix determinant: " << d << "\n";
    }
};


class Iter {
    vector<int> a;
public:
    Iter(vector<int> a) {
    }
    auto begin() {
        while (a.begin() != a.end()) return a.begin()++;
    }
    auto end() {
        return a.end();
    }
};

auto AddNumbersList(list <double> a) {
    double sum = 0.0;
    double result;
    sum = accumulate(a.begin(), a.end(), 1.0, [&](double a, double b) {
        return sum += a * b;
        });
    result = sum / a.size();
    return result;
}

int main(){
    list<double> numbers{2.0, 5.0, 6.5, 8.12, 1.9};
    copy(numbers.begin(), numbers.end(), ostream_iterator<float>(cout, " "));
    cout << endl;
    numbers.push_back(AddNumbersList(numbers));
    copy(numbers.begin(), numbers.end(), ostream_iterator<float>(cout, " "));
    cout << endl;
    
    Matrix mat;
    mat.determinant();

    vector<int> Digits;
    Iter it(Digits);
    for (const auto& m : it) {
        cout << m << " ";
    }

    return 0;
}


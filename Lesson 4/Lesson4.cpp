#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

template <typename box>
void insert_sorted(box& arr, int input) {
	arr.insert(upper_bound(arr.begin(), arr.end(), input), input);
}


int main(){
	//First Task
	int input;
	vector <int> arr(100);
	generate(arr.begin(), arr.end(), []() {return (rand() % 1002); });
	sort(arr.begin(), arr.end());
	for (const auto b : arr) cout << b << " ";
	cout << endl;
	cout << "Enter the number you want to input:";
	cin >> input;
	insert_sorted(arr, input);
	cout << endl;
	for (const auto b : arr) cout << b << " ";
	cout << "\n\n";


	//Second Task
	double a = 101;
	vector <double> real(100);
	generate(real.begin(), real.end(), [&a]() {return rand() * a / RAND_MAX; });
	for (const auto b : real) cout << b << " ";
	cout << "\n\n";

	vector <int> integer(100);
	copy(real.begin(), real.end(), integer.begin());
	for (const auto b : integer) cout << b << " ";
	cout << "\n\n";

	int n = 0;
	transform(real.begin(), real.end(), real.begin(), [&](double first) { return first - static_cast<double>(integer[n++]); });
	for (const auto b : real) cout << b << " ";
	cout << "\n\n";

	transform(real.begin(), real.end(), real.begin(), [](double first) { return first*first; });
	for (const auto b : real) cout << b << " ";
	cout << "\n\n";

	double totalerror = 0.0;
	cout << accumulate(begin(real), end(real), 0.0);
	cout << totalerror;
	
	return 0;
}

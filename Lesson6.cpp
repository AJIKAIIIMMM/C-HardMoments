#include <iostream>
#include <mutex>
#include <sstream>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;




class pcout : public ostringstream
{
public:
    pcout() = default;

    ~pcout()
    {
        lock_guard<mutex> guard(_mutexPrint);
        cout << this->str();
    }

private:
    static std::mutex _mutexPrint;
};

mutex pcout::_mutexPrint{};

bool isPrime(int& n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
        else
            continue;
    }
    return true;
}

void prime() {
    vector<int> primenumbers;
    int max = 1000000000;
    int j = 1;
    for (int i = 2; i <= max; i++) {
        if (isPrime(i) == true) {
            primenumbers.push_back(i);
            cout << "Prime number #" << j << ":" << primenumbers[j - 1] << " " << endl;
            this_thread::sleep_for(1s);
            j++;
        }
    }
}


void Owner(vector<int> *values) {
    for(int i = 0; i < 100; i++){
        values->push_back(rand() % 1000);
        this_thread::sleep_for(1s);
    }
}

void Thief(vector<int> *values){
    for (int i = 0; i < 100; i++) {
        sort(values->begin(), values->end());
        values->pop_back();
        this_thread::sleep_for(500ms);
    }
}


int main(){
    // Task #1
    int val = 0;
    pcout{} << "my_val=" << val << std::endl;

    // Task #2
    thread th1(prime);
    th1.join();

    // Task #3
    vector<int> values;
    for (int i = 0; i < 100; i++) {
        values.push_back(rand() % 500);
    }
    thread th2(Owner, &values);
    thread th3(Thief, &values);
    th2.join();
    th3.join();


    return 0;
}

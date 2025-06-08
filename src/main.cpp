#include <cstdint>
#include <iostream>
#include <boost/asio>

using namespace std;

int add(int a, int b);

int main() {
    int32_t a = 33;
    int32_t b = 44;
    cout << add(a, b) << endl;

    return 0;
}

int add(int a, int b) {
    return a + b;
}
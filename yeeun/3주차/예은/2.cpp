#include <iostream>
using namespace std;

int main(void) {
    int num;
    cout << "구구단 정보 입력: ";
    cin >> num;

    for(int i = 1; i < 10; i++) {
        cout << num << 'x' << i  << " = " << num * i << '\n';
    }

    return 0;
}
#include <iostream>
using namespace std;

int main(void) {
    int num = 0;
    int input;

    for(int i = 0; i < 5; i++) {
        cout << i+1 << "번째 정수 입력: ";
        cin >> input;
        num += input;
    }

    cout << "합계: " << num << '\n';
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void) {
    srand(time(NULL));
    for(int i = 1; i <= 5; i++) {
        printf("Random number #%d: %d\n", i, rand()%100);
    }

    return 0;
}
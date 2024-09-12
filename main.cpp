#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

const int width = 80;
const int height = 20;

const string itmo[5] = {
    "III TTTTT  M   M  OOO ",
    " I    T    MM MM O   O",
    " I    T    M M M O   O",
    " I    T    M   M O   O",
    "III   T    M   M  OOO "
};

void drawITMO(int offset) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < width; j++) {
            int pos = (j + offset) % width;
            if (pos < itmo[i].size()) {
                cout << itmo[i][pos];
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

int main() {
    int offset = 0;
    cout << "\x1b[2J"; // Очистка экрана

    while (true) {
        cout << "\x1b[H"; // Установка курсора в верхний левый угол
        drawITMO(offset);
        offset++;
        usleep(100000);
    }

    return 0;
}

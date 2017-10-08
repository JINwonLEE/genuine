#include <iostream>

void create_star(char** arr, int x, int y, int h);
using namespace std;

int main() {
    int height;
    cin >> height;

    char** array = new char*[height];
    for (int i = 0; i < height; i++) {
        array[i] = new char[2*height - 1];
        for (int j = 0; j < 2*height - 1; j++) {
            array[i][j] = ' ';
        }
    }
    
    create_star(array, 0, 0, height);
    
    for (int i =0; i < height; i++) {
        for (int j =0; j < height*2 - 1; j++) {
            cout << array[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}

void create_star(char** arr, int x, int y, int h) {
    if (h == 3) {
        arr[y][x + (2*h-1)/2] = '*';
        arr[y+1][x + (2*h-1)/2 - 1] = '*';
        arr[y+1][x + (2*h-1)/2 + 1] = '*';
        for (int i = 0; i < 5; i++) {
            arr[y+2][x + (2*h-1)/2 - 2 + i] = '*';
        }
        return;
    }
    else {
        create_star(arr, x + h/2, y, h/2);
        create_star(arr, x, y + h/2, h/2);
        create_star(arr, x + h, y + h/2, h/2);
    }
}

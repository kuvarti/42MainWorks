#include <iostream>
#include <iomanip>

using namespace std;

void draw(int n) {
    int size = 3 + 2*(n-1);
    int height = n + 2;
    int base = size * height;

    for (int i = 1, pos = 0; i <= height; i++) {
        int width = size + 2*(i-1);
        int pad = (base - width) / 2;

        for (int j = 0; j < width; j++) {
            if (j < pad || j >= pad + size) {
                cout << " ";
            } else {
                if (i == height && j == pad + size/2) {
                    cout << "|";
                } else {
                    cout << "*";
                }
            }
        }

        cout << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <n>" << endl;
        return 1;
    }

    int n = stoi(argv[1]);
    draw(n);

    return 0;
}


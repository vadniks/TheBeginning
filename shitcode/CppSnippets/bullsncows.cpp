

#include <iostream>

using namespace std;

int main() {
    const int l = 4;
    char n1[l]; // = { '5', '7', '3', '4' };
    char n2[l]; // = { '0', '7', '5', '5' };

    for (int i = 0; i < l; i++) {
        cout << "enter num1: ";
        cin >> n1[i];
        cout << " ";
    }

    cout << "\n";
    
    int r1 = 0;
    while (r1 != 4) {
        r1 = 0;

        for (int i = 0; i < l; i++) {
            cout << "enter num2: ";
            cin >> n2[i];
            cout << " ";
        }

    char r[l] = { 0 };
        int r2 = 0;

        for (int i = 0; i < l; i++) {
            if (n1[i] == n2[i]) {
                r[i] = '+';
                r1++;
                //cout << r1 << '+' << i << ' ' << n1[i] << ' ' << n2[i] << '\n';
            } else {
                for (int j = 0; j < l; j++) {
                    if (n1[i] == n2[j]) {
                        r[j] = '-';
                        r2++;
                        //cout << r2 << '-' << i << ' ' << n1[i] << ' ' << n2[i] << '\n';
                    }
                }
            }
        }

        cout << "\nscore: ";
        for (int i = 0; i < l; i++) {
            if (r[i] != 0)
                cout << r[i];
            else
                cout << '_';
        }
        cout << " | +: " << r1 << " -: " << r2 << "\n\n";
    }

    return 0;
}

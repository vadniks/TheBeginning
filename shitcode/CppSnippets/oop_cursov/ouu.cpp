
// output class implmenetation

#include "ouu.hpp"
#include <iostream>

// output (print)
void ouu::prt() {
    for (int i = 0, j = 0; i < xy; i++) {
        for (j = 0; j < xy; j++) {
            int a = mx[i][j];
			
            if (a == 2)
                cout << 'F';
            else
                cout << a;
        }
        if (i < xy-1) 
            cout << endl;
	}
}

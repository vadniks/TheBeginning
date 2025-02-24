
// implementation of the input class

#include "inn.hpp"
#include <iostream>

// input (scan)
void inn::scn() {
    ss s = new char[xy];
	
    for (int i = 0, j = 0; i < xy; i++) {
        cin >> s;

        for (j = 0; j < xy; j++)
            mx[i][j] = s[j] - '0';
	}
}

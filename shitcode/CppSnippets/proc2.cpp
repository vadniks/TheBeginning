

#include <iostream>



using namespace std;

 

void task1();

void task2();

void task3();

void task4();

void task5();

void task6();

void task8();

void task11();

void task12();

void task13();

void task14();

void task15();

 

int main() {

 

	//task1();

	//task2();

	//task3();

	//task4();

	//task5();

	//task6();

	//task8();

	//task11();

	//task12();

	//task13();

	//task14();

	task15();

 

	return 0;

}

 

void task1() {

	int s = 45;

 

	cout << "Enter V:";

	int v = 0;

	cin >> v;

 

	cout << "Enter T:";

	int t = 0;

	cin >> t;

 

	int s2 = v * t;

	int sc = s2 / 45;

 

	cout << s2 - (45 * sc);

}

 

void task2() {

	cout << "Enter num:";

	int n = 0;

	cin >> n;

 

	int nn = (n / 100) % 10;

 

	cout << nn;

}

 

void task3() {

	cout << "Enter D:";

	int d = 0;

	cin >> d;

 

	cout << "Enter S:";

	int s = 0;

	cin >> s;

 

	cout << s / d;

}

 

void task4() {

	cout << "Enter num:";

	int n = 0;

	cin >> n;

 

	cout << (n / 10) % 10;

}

 

void task5() {

	cout << "Enter X:";

	int x = 0;

	cin >> x;

 

	cout << "Enter Y:";

	int y = 0;

	cin >> y;

 

 

}

 

void task6() {

	cout << "Enter num:";

	int n = 0;

	cin >> n;

 

	while (n != 0) {

		int i = n % 10;

 

		if (i % 3 == 0)

			cout << i;

 

		n = n / 10;

	}

}

 

void task8() {

	int n = -1;

	int c = 0;

 

	do {

		cout << "Enter num:";

		cin >> n;

 

		if (n % 19 == 0 && n != 0)

			c++;

	} while (n != 0);

 

	cout << c;

}

 

void task11() {

	int a[5];

	int c = 0;

	int r = 0;

 

	do {

		cout << "Enter num:";

		cin >> a[c];

		c++;

	} while (c < 5);

 

	for (int i = 0; i < 5; i++) {

		if (a[i] % 7 == 0)

			r = r + a[i];

	}

 

	cout << r;

}

 

void task12() {

	int l = 0;

	cout << "Enter length:";

	cin >> l;

 

	int* a = new int[l];

	int c = 0;

	int max = 0;

 

	do {

		cout << "Enter num:";

		cin >> a[c];

		c++;

	} while (c < 10);

 

	for (int i = 0; i < 10; i++) {

		if (a[i] > max)

			max = a[i];

	}

 

	cout << max;

}

 

void task13() {

	int a[5][5] = {

		{ 1, 2, 3, 4, 5 },

		{ 3, 5, 2, 6, 9 },

		{ 4, 3, 6, 4, 3 },

		{ 5, 4, 2, 7, 5 },

		{ 5, 4, 2, 7, 5 }

	};

	int r = 0;

 

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			if (a[i][j] % 7 == 0)

				r += a[i][j];

		}

	}

 

	cout << r;

}

 

void task14() {

	char* a = (char*) "uhswreu98***(YP&*86f***(";

	char* b = new char[25];

 

	for (int i = 0; i < 25; i++) {

		if (a[i] != '*')

			b[i] = a[i];

	}

 

	cout << b;

}

 

void task15() {

	char a[10];

	char b[10];

	char c[10];

 

	cout << "Enter a:";

	gets(a);

	cout << "Enter b:";

	gets(b);

	cout << "Enter c:";

	gets(c);

 

	char a1 = a[0];

	char b1 = b[0];

	char c1 = c[0];

 

	char d[6];

	d[0] = a1;

	d[1] = '.';

	d[2] = b1;

	d[3] = '.';

	d[4] = c1;

	d[5] = '.';

	cout << d;

}

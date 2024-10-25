#include <iostream>
#include <cmath>
#include <Windows.h>

int main() {
	float x, y, a;
	
	system("color 0c");
	for (y = 1.5; y > -1.5; y -= 0.1) {
		for (x = -1.5; x < 1.5; x += 0.05) {
			a = pow(x, 2) + pow(y, 2) - 1;
			putchar(pow(a, 3) - pow(x, 2) * pow(y, 3) <= 0.0 ? '*' : ' ');
		}
		putchar('\n');
		Sleep(50);
	}
	std::cout << ("\t\t\t[I love U <3]\n");
	
	return 0;
}

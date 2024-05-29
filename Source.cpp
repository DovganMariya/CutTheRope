#include<iostream>
#include<clocale>
#include<algorithm>
#include<Windows.h>

using namespace std;
int main() {
	std::ofstream output_file("output.txt");
	std::ifstream input_file("input.txt");
	setlocale(LC_ALL, "Russian");
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	Dovgan_string a;
	Dovgan_string iff="if";
	int ifcount = 0, elsecount = 0, thencount = 0;
	input_file>>a;
	cout << a << endl;
	for (int i = 0; i < a.length(); i++) {
		if (a.substr(i, 1) == iff) {
			ifcount++;
		}
	}
	cout << ifcount;
}
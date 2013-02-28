#include <iostream>
#include <fstream>
using namespace std;

int sum(int x, int y) {
	int result = x + y;
	return result;
}

void my_swap(int x, int y) {
	int temp = x;
	x = y;
	y = x;
}

int main() {
	// declare a pointer to an integer
	int *ptr;

	int number = 42;

	// initialize the pointer with address 
	ptr = &number;


	// dynamically allocating memory
	double *ptr_d = new double;

	*ptr_d = 142;
	cout << *ptr_d << endl;

	delete ptr_d;

	// references
	int &ref = number;

	cout << ref << ' ' << number << endl;

	// pointer to nothing
	string *ptr_s = nullptr;

	// calling a function
	int r = sum(16, 42);
	cout << "Sum of 16 and 42 is " << r << endl;

	// calling mechanism
	int x = 16;
	int y = 42;

	// outputs: 16 42
	cout << x << " " << y << endl;

	// call function here

	// outputs: 42 16
	cout << x << " " << y << endl;

	// reading files
	ifstream dat_in("filename.txt");

	if (!dat_in) {
		cerr << "Error opening 'filename.txt'" << endl;
		return 1;
	}

	// read from file
	while (!dat_in.eof()) {
		int value;
		dat_in >> value;

		cout << value << ' ';
	}

	// write to file
	ofstream dat_out("fileout.txt");

	if (!dat_out) {
		cerr << "Error creating 'fileout.txt'" << endl;
		return 2;
	}

	int num;
	do {
		cout << "Enter an integer: ";
		cin >> num;

		if (num != 0) {
			dat_out << num << ' ';
		}
	} while (num != 0);

	// write to binary file
	ofstream dat_out_bin("numbers.bin", ios_base::binary);

	if (!dat_out_bin) {
		cerr << "Error creating file 'numbers.bin'" << endl;
		return 3;
	}

	// write some numbers
	for (int i = 16; i <= 42; ++i) {
		const char *from_addr = reinterpret_cast<const char *>(&i);
		dat_out_bin.write(from_addr, sizeof(int));
	}

	// read from binary file
	dat_out_bin.close();

	ifstream dat_in_bin("numbers.bin", ios_base::binary);
	if (!dat_in_bin) {
		cerr << "Error opening file 'numbers.bin'" << endl;
		return 4;
	}

	cout << endl;
	// read some numbers
	while (!dat_in_bin.eof()) {
		int value;
		char *to_addr = reinterpret_cast<char *>(&value);
		dat_in_bin.read(to_addr, sizeof(int));

		cout << value << " ";
	}

	return 0;
}
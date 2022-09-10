#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int size { 20 }, min_n { 0 }, max_n { 20 };

void gen_massive(int mass[], int size = ::size);
void print_massive(int mass[], int size = ::size);
int get_max_element(int mass[], int size = ::size);
int get_min_element(int mass[], int size = ::size);
int get_even_elements(int mass[], int size = ::size);
int get_odd_elements(int mass[], int size = ::size);
bool is_prime(int n);
int get_prime_number_elements(int mass[], int size = ::size);
void revers_massive(int mass[], int size = ::size);
int menu();

int main() {
	int arr[::size] { };
	int op { 0 };
	enum operations {
		EXIT, MAX, MIN, EVEN, ODD, PRIME, REVERSE, REGEN
	};

	gen_massive(arr);
	do {
		print_massive(arr);
		op = menu();
		switch (op) {
		case EXIT:
			return 0;
		case MIN:
			cout << "The min element is " << get_min_element(arr) << endl;
			break;
		case MAX:
			cout << "The max element is " << get_max_element(arr) << endl;
			break;
		case EVEN:
			cout << "The number of even elements is " << get_even_elements(arr)
					<< endl;
			break;
		case ODD:
			cout << "The number of odd elements is " << get_odd_elements(arr)
					<< endl;
			break;
		case PRIME:
			cout << "The number of prime elements is "
					<< get_prime_number_elements(arr) << endl;
			break;
		case REVERSE:
			revers_massive(arr);
			break;
		case REGEN:
			gen_massive(arr);
			break;
		default:
			cout << "Wrong command!" << endl;
			break;
		}

	} while (op);

	return 0;
}

void gen_massive(int mass[], int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		mass[i] = ::min_n + rand() % (::max_n - ::min_n + 1);
	}
}

void print_massive(int mass[], int size) {
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}

int get_max_element(int mass[], int size) {
	int max { mass[0] };
	for (int i = 0; i < size; i++) {
		if (mass[i] > max)
			max = mass[i];
	}
	return max;
}

int get_min_element(int mass[], int size) {
	int min { mass[0] };
	for (int i = 0; i < size; i++) {
		if (mass[i] < min)
			min = mass[i];
	}
	return min;
}

int get_even_elements(int mass[], int size) {
	int even { 0 };
	for (int i = 0; i < size; i++) {
		if (!(mass[i] % 2))
			even++;
	}
	return even;
}

int get_odd_elements(int mass[], int size) {
	int odd { 0 };
	for (int i = 0; i < size; i++) {
		if (mass[i] % 2)
			odd++;
	}
	return odd;
}

bool is_prime(int n) {
	for (int i = 2; i < n / 2; i++) {
		if (!(n % i))
			return false;
	}
	return true;
}

int get_prime_number_elements(int mass[], int size) {
	int prime { 0 };
	for (int i = 0; i < size; i++) {
		if (is_prime(mass[i]))
			prime++;
	}
	return prime;
}

void revers_massive(int mass[], int size) {
	int t { 0 };
	for (int i = 0; i < size / 2; i++) {
		t = mass[i];
		mass[i] = mass[size - i - 1];
		mass[size - i - 1] = t;
	}
}

int menu() {
	int op { 0 };
	cout << "Enter your command:" << endl;
	cout << "1. Return max element of the array" << endl;
	cout << "2. Return min element of the array" << endl;
	cout << "3. Return number of even elements in the array" << endl;
	cout << "4. Return number of odd elements in the array" << endl;
	cout << "5. Return number of prime elements in the array" << endl;
	cout << "6. Reverse the array" << endl;
	cout << "7. Generate the array anew" << endl;
	cout << "0. Exit" << endl;
	cin >> op;
	return op;
}

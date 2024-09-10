#include "Functions.h"

using namespace std;

void readArrayFromFile(int*& arr, int& size, const string& filename) {
	ifstream file(filename);
	if (!file) {
		throw runtime_error("Failed to open the file");
	}
	size = 0;
	while (!file.eof()) {
		int temp;
		file >> temp;
		if (file) {
			addValue(arr, size, temp);
		}
	}
	file.close();
}

void addValue(int*& arr, int& size, int newValue) {
	int* newArr = new int[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	newArr[size] = newValue;
	delete[] arr;
	arr = newArr;
	size++;
}

int findIndex(int arr[], int size, int value) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i;
		}
		else if (i == size) {
			return -1;
		}
	}
}

void modifyValue(int arr[], int size, int index, int newValue) {
	try {
		if (index < 0 || index >= size) {
			throw out_of_range("Index out of range");
		}
		else {
			int oldInt = arr[index];
			arr[index] = newValue;
			cout << "Old number: " << oldInt << " at index " << index << endl;
			cout << "New number: " << newValue << " at index " << index << endl;
		}
	}
	catch (const out_of_range& e) {
		// Handle the exception
		cout << e.what() << endl;
	}
}

void removeValue(int*& arr, int& size, int index) {
	int* newArr = new int[size - 1];
	for (int i = 0, j = 0; i < size; ++i) {
		if (i != index) {
			newArr[j++] = arr[i];
		}
	}
	delete[] arr;
	arr = newArr;
	size--;
}

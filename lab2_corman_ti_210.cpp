#include <iostream>

using namespace std;

void getMaxValue(float *arr, int arrSize) {

	float maxValue = *arr;
	
	for (int i = 0; i < arrSize; i++) {
		
		if (arr[i] > maxValue) {
			maxValue = arr[i];
		}

	}

	cout << "Max index in array is:\t" << maxValue << endl;

	return;
}

void getSumm(float *arr, int arrSize) {

	float summArr = 0;

	for (int i = arrSize - 1; i > -1; i--) {

		if (arr[i] < 0) {
			
			for (int k = 0; k < i; k++) {
				summArr += arr[k];
			}

			break;

		} else {
			continue;
		}

	}

	cout << "Summ of elements before last negative number:\t" << summArr << endl;

	return;
}

void reduceArray(float *arr, const int arrSize, int a, int b) {

	float newArr[8];

	int pointerA = 0;
	int pointerB = a;

	for (int i = 0; i < arrSize; i++) {

		if (pointerA < a) {

			newArr[i] = arr[pointerA];
			pointerA++;

		}

		if (i > b) {

			newArr[pointerB] = arr[i];
			pointerB++;

		}

	}

	for (int i = pointerB; i < arrSize; i++) {
		newArr[i] = 0;
	}
	
	cout << "Sorted array" << endl;

	for (int i = 0; i < arrSize; i++) {
		cout << newArr[i] << "\t";
	}
	
	return;
}


int main() {

	const int n = 8;
	
	cout << "Enter element in array" << endl;
	float arr[n] = {-45., 13., 0., 100., 156., -23., 55., 0.};

	// for (int i = 0; i < n; i++) {
		
	// 	cout << "m[" << i << "] = "; cin >> arr[i];

	// }

	cout << endl;

	getMaxValue(arr, n);
	cout << endl;
	getSumm(arr, n);
	cout << endl;
	reduceArray(arr, n, 3, 30);
	cout << endl;

	return 0;
}
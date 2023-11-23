#include <iostream>

using namespace std;

class Algo {
public:
	void bSearch(int a[], int n, int target) {
		int l = 0;
		int r = n - 1;

		while (l <= r) {
			int mid = l + (r - l) / 2;
			int value = a[mid];
			cout << "Middle" << value << endl;

			if (value < target) {
				l = mid + 1;
			}
			else if (value > target) {
				r = mid - 1;
			}
			else {
				cout << mid;
			}
		}
	}

	void swap(int* ptr1, int* ptr2) {
		int temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
	}

	void bub(int n, int a[]) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - i - 1; ++j) {
				if (a[j] > a[j + 1]) {
					swap(&a[j], &a[j + 1]);
				}
			}
		}
	}

	void selectionSort(int n, int a[]) {
		int min_pos;
		for (int i = 0; i < n - 1; i++) {
			min_pos = i;
			for (int j = i + 1; j < n; ++j) { 
				if (a[j] < a[min_pos]) {
					min_pos = j;
				}
			}
			if (min_pos != i) {
				swap(&a[i], &a[min_pos]);
			}
		}
		for (int k = 0; k < n; ++k) {
			cout << a[k] << " " << endl;
		}
	}

	void insertionSort(int n, int a[]) {
		int j, i, key;

		for (j = 1; j < n; ++j) {
			key = a[j];
			i = j - 1;
			while (i >= 0 && a[i] > key) {
				a[i + 1] = a[i];
				i--;
			}
			a[i + 1] = key;
		}
		for (int i = 0; i < n; ++i) {
			cout << a[i] << endl;
		}
	}

	void shuffleArray(int a[], int size) {
		srand(time(NULL));

		for (int i = size - 1; i > 0; i--) {
			int j = rand() % (i + 1);
			swap(&a[i], &a[j]);
		}
	}

};


int main(void) {
	int a[100];
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	
	Algo algo;
	algo.shuffleArray(a, n);

	//algo.selectionSort(n, a);
	//algo.insertionSort(n, a);
	//algo.bub(n, a);
	
	
}

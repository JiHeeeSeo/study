// 포인터를 사용해서 배열을 거꾸로 만드는 프로그램
#include <iostream>
using namespace std;

void reverse(int*, int);

int main() {
	// 배열 선언, 초기화
	int arr[5] = { 10, 11, 12, 13, 14 };
	// 함수 호출
	reverse(arr, 5);
	cout << "배열 거꾸로 출력: ";
	for (int i = 0; i < 5; i++) {
		cout << *(arr + i) << "  ";
	}
	return 0;
}

// 배열에 대한 포인터와 배열의 크기를 매개변수로 전달받아서 배열을 거꾸로 반전하는 함수
void reverse(int* pArr, int size) {
	int i = 0;
	int j = size - 1;
	while (i < size / 2) {
		int temp = *(pArr + i);
		*(pArr + i) = *(pArr + j);
		*(pArr + j) = temp;
		i++;
		j--;
	}
}
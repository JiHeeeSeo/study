/* 포인터로 전달을 사용해서 함수로 전달한
2개의 값을 스왑하는 프로그램*/
#include <iostream>
using namespace std;

void swap(int* first, int* second);

int main() {
	// 변수 2개 정의
	int x = 10;
	int y = 20;

	// 스왑하기 전에 x와 y의 값 출력
	cout << "스왑하기 전의 x와 y의 값" << endl;
	cout << "x: " << x << " " << "y: " << y << endl;

	// swap 함수를 호출해서 변수 x와 y 스왑
	swap(&x, &y);
	cout << "스왑 후의 x와 y의 값" << endl;
	cout << "x: " << x << " " << "y: " << y << endl;
	return 0;
}

void swap(int* pX, int* pY) {
	int tmp = *pX;
	*pX = *pY;
	*pY = tmp;
}
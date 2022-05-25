/* 프로그램이 존재하는 동안 계속해서 메모리에 존재하는 전역변수, 정적 변수를 사용하는 프로그램*/
#include <iostream>
using namespace std;

int first = 20;				// 정적 메모리 위에 올라가는 전역 변수
static int second = 30;		// 정적 메모리 위에 올라가는 전역 정적 변수

int main() {
	static int third = 50;	// 정적 메모리 위에 올라가는 정적 변수

	cout << "전역 변수의 값: " << first << endl;
	cout << "전역 정적 변수의 값: " << second << endl;
	cout << "지역 정적 변수의 값: " << third<<endl;
}
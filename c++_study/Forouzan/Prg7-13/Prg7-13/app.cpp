﻿/* Time 객체를 사용하는 app.cpp 애플리케이션 파일 */
#include "time.h"

int main() {
	// Time 객체 초기화
	Time time(4, 5, 27);
	// 원래 시간 출력
	cout << "원래 시간: ";
	time.print();
	// 원본 시간에 143500초 추가
	for (int i = 0; i < 143500; i++)
		time.tick();
	//143500초 후의 시간 출력
	cout << "143500초가 지나면: ";
	time.print();
	return 0;
}
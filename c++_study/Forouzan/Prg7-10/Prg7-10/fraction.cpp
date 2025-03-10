﻿/* Fraction 클래스의 멤버 함수들을 정의하는
   fraction.cpp 인터페이스 파일 */
#include <iostream>
#include <cmath>
#include <cassert>
#include "fraction.h"
using namespace std;

/* 매개변수 있는 생성자는 불변 속성에 따라서
분자와 분모 값을 받고 약분하여 분수 객체를 생성*/
Fraction::Fraction(int num, int den):numer(num), denom(den){
	normalize();
}

/* 기본 생성자는 0/1을 생성
별도의 유효성 검사가 필요하지 않음*/
Fraction::Fraction():numer(0),denom(1)
{
}

/* 복사 생성자는 기본의 객체가 가진 분자와 분모를 활용해서 객체를 복사
이미 복사 대상이 약분이 되어 있을 것이므로
약분 처리를 따로 하지 않아도 됨*/
Fraction::Fraction(const Fraction& fract):numer(fract.numer), denom(fract.denom)
{
}

/* 소멸자에서는 별도의 작업은 따로 하지 않음 */
Fraction::~Fraction()
{
}

/* getNumber 함수는 접근자 함수
호스트 객체의 분자를 리턴*/
int Fraction::getNumer() const
{
	return numer;
}

/* getDenum 함수는 접근자 함수
호스트 객체의 분모를 리턴*/
int Fraction::getDenom() const
{
	return denom;
}

/* print 함수는 접근자 함수
화면에 분수 객체를 x/y 형태로 출력하는 부자 작용을 만듦*/
void Fraction::print() const{
	cout << numer << "/" << denom << endl;
}

/* setNumer 함수는 설정자 함수
분자의 값을 변경하고 약분*/
void Fraction::setNumer(int num){
	numer = num;
	normalize();
}

/* setDenom 함수는 설정자 함수
분모의 값을 변경하고 약분*/
void Fraction::setDenom(int den){
	denom = den;
	normalize();
}
/* normalize 함수는 3가지 작업을 통해 분수를 약분 */
void Fraction::normalize(){
	// 분모가 0인 경우
	if (denom == 0) {
		cout << "잘못된 분모 값입니다. 프로그램을 중단합니다." << endl;
		assert(false);
	}

	// 분모와 분자의 부호 변경
	if (denom < 0) {
		denom = -denom;
		numer = -numer;
	}
	
	// 최대 공약수로 분자와 분모 나누기
	int divisor = gcd(abs(numer), abs(denom));
	numer = numer / divisor;
	denom = denom / divisor;
}

/* gcd 함ㅅ는 분자와 분모의
최대 공약수 찾음*/
int Fraction::gcd(int n, int m){
	int gcd = 1;
	for (int k = 1; k <= n && k <= m; k++) {
		if (n % k== 0 && m % k == 0) {
			gcd = k;
		}
	}
	return gcd;
	return 0;
}

#include "main_header.h"
#include "Person.h"

Person::Person(const char* regist_no, const char* person_name) : Animal(2, person_name) {
	strcpy(this->regist_no, regist_no);
}

void Person::printInfo() {
	printf("사람이름: %s, 주민등록번호: %s\n", name, regist_no);
}
#define _CRT_SECURE_NO_WARNINGS

#include "./Date.h"
#include <iostream>

//ȫȱʡ�Ĺ��캯��
Date::Date(int year, int month, int day) :
	_year(year),
	_month(month),
	_day(day) {
	;
}

//��������
Date::Date(const Date& d) :
	_year(d._year),
	_month(d._month),
	_day(d._day) {
	;
}

//��ֵ���������
Date& Date::operator=(const Date& d) {
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
	return *this;
}

//��������
Date::~Date() { ; }

inline bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Date::GetMonthDay(int year, int month) {
	int monthArr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30 };
	//if leap-year	���꽫���µ������滻Ϊ29
	//�ܱ�4���������ܱ�100�����������ܱ�400����
	if (isLeapYear(year))
		monthArr[1]++;
	return monthArr[month - 1];
}

//����+=����
Date& Date::operator+=(int day) {
	//������, ����������վ��Ƕ�Ӧ����
	this->_day += day;
	while (this->_day > GetMonthDay(this->_year, this->_month)) {
		//������
		this->_day -= GetMonthDay(this->_year, this->_month);
		this->_month++;
		//������
		if (this->_month >= 13) {
			this->_year++;
			this->_month = 1;
		}
	}
	return *this;
}

//����+����
Date Date::operator+(int day)const {
	Date temp = *this;
	return temp += day;
}

//����-����
Date& Date::operator-=(int day) {
	//�ռ���, ����������վ��Ƕ�Ӧ����
	this->_day -= day;
	while (this->_day < 1) {
		//�¼���
		this->_month--;
		//�����
		if (this->_month <= 0) {
			this->_month = 12;
			this->_year--;
		}
		this->_day += GetMonthDay(this->_year, this->_month);
	}
	return *this;
}

//����+����
Date Date::operator-(int day)const {
	Date temp = *this;
	return temp -= day;
}

#pragma region �����Լ�����

Date& Date::operator++() {
	Date temp = (*this);
	(*this) += 1;
	return temp;
}

Date Date::operator++(int) {
	return (*this) += 1;
}

Date& Date::operator--() {
	Date temp = (*this);
	(*this) -= 1;
	return temp;
}

Date Date::operator--(int) {
	return (*this) -= 1;
}

#pragma endregion

#pragma region ��ϵ���������

bool Date::operator>(const Date& d)const {
	int cmp = compare(d);
	return cmp > 0;
}

bool Date::operator>=(const Date& d)const {
	int cmp = compare(d);
	return cmp >= 0;
}

bool Date::operator<(const Date& d)const {
	int cmp = compare(d);
	return cmp < 0;
}

bool Date::operator<=(const Date& d)const {
	int cmp = compare(d);
	return cmp <= 0;
}

bool Date::operator==(const Date& d)const {
	int cmp = compare(d);
	return cmp == 0;
}

bool Date::operator!=(const Date& d)const {
	int cmp = compare(d);
	return cmp != 0;
}

//����a��b�Ĵ�С��ϵ
int Date::compare(const Date& right)const {
	if (this->_year - right._year != 0)
		return this->_year - right._year;
	else if (this->_month - right._month != 0)
		return this->_month - right._month;
	else
		return this->_day - right._day;
}

#pragma endregion

int Date::operator-(const Date& d) const {
	int cmp = 0;

	Date* max = new Date(*this);
	Date* min = new Date(d);
	//�Ҽ�ֵ
	if ((*max) < (*min)) {
		std::swap(max, min);
	}
	while ((*max) > (*min)) {
		(*max)--;
		cmp++;
	}
	return cmp;
}

//�������
std::ostream& operator<<(std::ostream& dest, const Date& src) {
	return dest << src._year << "\\" << src._month << "\\" << src._day;
}

//��������
std::istream& operator>>(std::istream& src, Date& dest) {
	char temp = 0;
	return src >> dest._year >> temp >> dest._month >> temp >> dest._day;
}
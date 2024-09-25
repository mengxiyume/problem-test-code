#define _CRT_SECURE_NO_WARNINGS

#include "./Date.h"

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

int Date::GetMonthDay(int year, int month) {
	int monthArr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30 };
	//if leap-year	���꽫���µ������滻Ϊ29
	//�ܱ�4���������ܱ�100�����������ܱ�400����
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
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
Date Date::operator+(int day) {
	return (*this) += day;
}

//����-����
Date& Date::operator-=(int day) {
	//�ռ���, ����������վ��Ƕ�Ӧ����
	this->_day -= day;
	while (this->_day < GetMonthDay(this->_year, this->_month)) {
		//�¼���
		this->_day += GetMonthDay(this->_year, this->_month);
		this->_month--;
		//�����
		if (this->_month <= 0) {
			this->_year--;
			this->_month = 12;
		}
	}
	return *this;
}

//����+����
Date Date::operator-(int day) {
	return (*this) -= day;
}

Date& Date::operator++() {
	Date temp = (*this);
	(*this) += 1;
	return temp;
}

Date Date::operator++(int) {
	return (*this) += 1;
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
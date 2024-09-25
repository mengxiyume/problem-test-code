#define _CRT_SECURE_NO_WARNINGS

#include "./Date.h"
#include <iostream>

//全缺省的构造函数
Date::Date(int year, int month, int day) :
	_year(year),
	_month(month),
	_day(day) {
	;
}

//拷贝构造
Date::Date(const Date& d) :
	_year(d._year),
	_month(d._month),
	_day(d._day) {
	;
}

//赋值运算符重载
Date& Date::operator=(const Date& d) {
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
	return *this;
}

//析构函数
Date::~Date() { ; }

inline bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Date::GetMonthDay(int year, int month) {
	int monthArr[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30 };
	//if leap-year	闰年将二月的天数替换为29
	//能被4整除但不能被100整除，或者能被400整除
	if (isLeapYear(year))
		monthArr[1]++;
	return monthArr[month - 1];
}

//日期+=天数
Date& Date::operator+=(int day) {
	//日增长, 到最后保留的日就是对应的日
	this->_day += day;
	while (this->_day > GetMonthDay(this->_year, this->_month)) {
		//月增长
		this->_day -= GetMonthDay(this->_year, this->_month);
		this->_month++;
		//年增长
		if (this->_month >= 13) {
			this->_year++;
			this->_month = 1;
		}
	}
	return *this;
}

//日期+天数
Date Date::operator+(int day)const {
	Date temp = *this;
	return temp += day;
}

//日期-天数
Date& Date::operator-=(int day) {
	//日减少, 到最后保留的日就是对应的日
	this->_day -= day;
	while (this->_day < 1) {
		//月减少
		this->_month--;
		//年减少
		if (this->_month <= 0) {
			this->_month = 12;
			this->_year--;
		}
		this->_day += GetMonthDay(this->_year, this->_month);
	}
	return *this;
}

//日期+天数
Date Date::operator-(int day)const {
	Date temp = *this;
	return temp -= day;
}

#pragma region 自增自减重载

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

#pragma region 关系运算符重载

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

//返回a与b的大小关系
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
	//找极值
	if ((*max) < (*min)) {
		std::swap(max, min);
	}
	while ((*max) > (*min)) {
		(*max)--;
		cmp++;
	}
	return cmp;
}

//输出日期
std::ostream& operator<<(std::ostream& dest, const Date& src) {
	return dest << src._year << "\\" << src._month << "\\" << src._day;
}

//输入日期
std::istream& operator>>(std::istream& src, Date& dest) {
	char temp = 0;
	return src >> dest._year >> temp >> dest._month >> temp >> dest._day;
}
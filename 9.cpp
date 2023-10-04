#include<iostream>
using namespace std;

class Date {
	
	int _day, _month, _year;

public:
	Date(int day = 0, int month = 0, int year = 0) {
		_day = day;
		_month = month;
		_year = year;
	}

	Date operator+(int days) {
		int total_days = (_year * 360) + (_month * 30) + _day + days;
		int new_year = total_days / 360;
		total_days %= 360;
		int new_month = total_days / 30;
		int new_day = total_days % 30;
		return Date(new_day, new_month, new_year);
	}

	friend ostream& operator<<(ostream& os, const Date& date) {
		return os << date._day << "." << date._month << "." << date._year;
	}
};

int main(int argc, char* argv[])
{
	Date begin_task = Date(13, 4, 2023);
	cout << "Die Aufgabe beginnt am " << begin_task << endl;
	Date end_task = begin_task + 7;
	cout << "Die Aufgabe endet am " << end_task << endl;
	Date one_year_and_one_month_later = begin_task + 390;
	cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
	Date three_years_and_five_months_later = begin_task + 1230;
	cout << "Drei Jahre und 5 Monate nach Aufgabenbeginn ist der " << three_years_and_five_months_later << endl;

	return 0;
}

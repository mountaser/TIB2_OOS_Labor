#include <string>
using namespace std;

/* HIER */
#pragma once
#include "Employee.h"

class Worker : public Employee /* HIER */
{
    double _hourly_earnings;
    double _hours;

public:
    Worker(const string, const string, double = 0.0, double = 0.0);
    double get_income() const;
    void print() const;
};
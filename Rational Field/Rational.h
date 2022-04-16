#pragma once

#include <iostream>

typedef long long int lli;

class Q {

private:
	lli numerator;
	lli denominator;

	void adjust();
	lli gcd(lli m, lli n);
public:

	Q();
	Q(lli n);
	Q(lli p, lli q);

	bool isNaN() const;
	static Q NaN();

	lli p() const;
	lli q() const;

	Q operator+(const Q other) const;
	Q operator-(const Q other) const;
	Q operator*(const Q other) const;
	Q operator/(const Q other) const;
	Q operator%(const Q other) const;

	Q operator+() const;
	Q operator-() const;
	Q operator~() const;

	Q& operator+=(const Q other);
	Q& operator-=(const Q other);
	Q& operator*=(const Q other);
	Q& operator/=(const Q other);
	Q& operator%=(const Q other);

	Q& operator++();
	Q operator++(int);

	Q& operator--();
	Q operator--(int);

	bool operator==(const Q other) const;
	bool operator!=(const Q other) const;

	bool operator< (const Q other) const;
	bool operator<=(const Q other) const;

	bool operator> (const Q other) const;
	bool operator>=(const Q other) const;

	operator int();
	operator lli();
	operator float();
	operator double();

	friend std::ostream& operator<<(std::ostream& os, const Q number);
};
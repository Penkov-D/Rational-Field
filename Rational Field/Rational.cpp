#include "Rational.h"

/* ================[     Fix Number      ]================ */

void Q::adjust() {
	if (denominator == 0)
		return;
	
	lli devider = gcd(numerator, denominator);
	numerator /= devider;
	denominator /= devider;

	if (denominator < 0) {
		denominator = -denominator;
		numerator = -numerator;
	}
}

lli Q::gcd(lli n, lli m) {
	if (n % m == 0)
		return m;
	return gcd(m, n % m);
}



/* ================[    Constractors     ]================ */

Q::Q() : numerator(0), denominator(1) {}

Q::Q(lli n) : numerator(n), denominator(1) {}

Q::Q(lli p, lli q) : numerator(p), denominator(q) { adjust(); }



/* ================[     Components      ]================ */

lli Q::p() const { return numerator; }

lli Q::q() const { return denominator; }



/* ================[    Not a Number     ]================ */

bool Q::isNaN() const { return denominator == 0; }

Q Q::NaN() { return Q(0, 0); }



/* ================[     Arithmetic      ]================ */

Q Q::operator+(const Q other) const {
	return Q(
		numerator * other.denominator + other.numerator * denominator,
		denominator * other.denominator
	);
}

Q Q::operator-(const Q other) const {
	return Q(
		numerator * other.denominator - other.numerator * denominator,
		denominator * other.denominator
	);
}

Q Q::operator*(const Q other) const {
	return Q(
		numerator * other.numerator,
		denominator * other.denominator
	);
}

Q Q::operator/(const Q other) const {
	if (other.isNaN())
		return NaN();

	return Q(
		numerator * other.denominator,
		denominator * other.numerator
	);
}

Q Q::operator%(const Q other) const {
	if (isNaN() || other.isNaN())
		return NaN();

	return Q(
		(numerator * other.denominator) % (other.numerator * denominator),
		denominator * other.denominator
	);
}

Q Q::operator+() const {
	return *this;
}

Q Q::operator-() const {
	return Q(-numerator, denominator);
}

Q Q::operator~() const {
	if (isNaN())
		return NaN();

	return Q(denominator, numerator);
}



/* ================[     Assignment      ]================ */

Q& Q::operator+=(const Q other) { return (*this = *this + other); }

Q& Q::operator-=(const Q other) { return (*this = *this - other); }

Q& Q::operator*=(const Q other) { return (*this = *this * other); }

Q& Q::operator/=(const Q other) { return (*this = *this / other); }

Q& Q::operator%=(const Q other) { return (*this = *this % other); }



/* ================[   Inc/Dec-rement    ]================ */

Q& Q::operator++() {
	return (*this += 1);
}

Q Q::operator++(int) {
	Q q = *this;
	*this += 1;
	return q;
}

Q& Q::operator--() {
	return (*this -= 1);
}

Q Q::operator--(int) {
	Q q = *this;
	*this -= 1;
	return q;
}



/* ================[       Casting       ]================ */

Q::operator int() {
	return (int)((lli) *this);
}

Q::operator lli() {
	if (isNaN())
		return -1L;
	return numerator / denominator;
}

Q::operator float() {
	return (float)((double)*this);
}

Q::operator double() {
	if (isNaN())
		return NAN;
	return double(numerator) / double(denominator);
}



/* ================[     Comparison      ]================ */

bool Q::operator==(const Q other) const {
	return numerator == other.numerator && denominator == other.denominator && !isNaN() && !other.isNaN();
}

bool Q::operator!=(const Q other) const {
	return !(*this == other);
}

bool Q::operator< (const Q other) const {
	return ((numerator * other.denominator) < (other.numerator * denominator)) && !isNaN() && !other.isNaN();
}

bool Q::operator<=(const Q other) const {
	return (!(other < *this) && !isNaN() && !other.isNaN());
}

bool Q::operator> (const Q other) const {
	return other < *this;
}

bool Q::operator>=(const Q other) const {
	return (!(*this < other) && !isNaN() && !other.isNaN());
}



/* ================[       Output        ]================ */

std::ostream& operator<<(std::ostream& os, const Q number) {
	if (number.isNaN())
		os << "NaN";
	else
		os << number.numerator << "/" << number.denominator;

	return os;
}
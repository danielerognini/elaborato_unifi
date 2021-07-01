#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(const int& x, const int& y) : x(x), y(y) {}

Vector2D Vector2D::toCartesian(const double& radius, const double& angle) {
    return Vector2D(round(radius * cos(angle)), round(radius * sin(angle)));
}

//Methods for the various math operations:
void Vector2D::add(const Vector2D& vector) {
    this->x += vector.x;
    this->y += vector.y;
}
void Vector2D::subtract(const Vector2D& vector) {
    this->x -= vector.x;
    this->y -= vector.y;
}
void Vector2D::multiply(const int& scalar) {
    this->x *= scalar;
    this->y *= scalar;
}
void Vector2D::divide(const int& scalar) {
    this->x /= scalar;
    this->y /= scalar;
}

//overriding the operators
Vector2D Vector2D::operator+(const Vector2D& right) {
    return Vector2D(this->x + right.x, this->y + right.y);
}
Vector2D Vector2D::operator-(const Vector2D& right) {
    return Vector2D(this->x - right.x, this->y - right.y);
}
Vector2D Vector2D::operator*(const int& scalar) {
    return Vector2D(this->x * scalar, this->y * scalar);
}
Vector2D Vector2D::operator/(const int& scalar) {
    return Vector2D(this->x / scalar, this->y / scalar);
}

//we also want to override the +=, -=, ... operators
Vector2D& Vector2D::operator+=(const Vector2D& vector) {
    add(vector);
    return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& vector) {
    subtract(vector);
    return *this;
}
Vector2D& Vector2D::operator*=(const int& scalar) {
    multiply(scalar);
    return *this;
}
Vector2D& Vector2D::operator/=(const int& scalar) {
    divide(scalar);
    return *this;
}

const int& Vector2D::getX() const {
    return x;
}

void Vector2D::setX(const int& x) {
    this->x = x;
}

const int& Vector2D::getY() const {
    return y;
}

void Vector2D::setY(const int& y) {
    this->y = y;
}

void Vector2D::add(const int& x, const int& y) {
    this->x += x;
    this->y += y;
}

void Vector2D::subtract(const int& x, const int& y) {
    this->x -= x;
    this->y -= y;
}

double Vector2D::operator%(Vector2D &right) {
    Vector2D vector = right - (*this);
    return sqrt(vector.x * vector.x + vector.y * vector.y);
}

void Vector2D::setVector(const int& x, const int& y) {
    this->x = x;
    this->y = y;
}

#include "Vector2D.h"

Vector2D::Vector2D(int x, int y) : x(x), y(y) {}

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
Vector2D& Vector2D::setToZero() {
    x = 0;
    y = 0;
}

int Vector2D::getX() const {
    return x;
}

void Vector2D::setX(int x) {
    this->x = x;
}

int Vector2D::getY() const {
    return y;
}

void Vector2D::setY(int y) {
    this->y = y;
}

void Vector2D::add(const int x, const int y) {
    this->x += x;
    this->y += y;
}

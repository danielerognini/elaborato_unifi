#ifndef GAME_VECTOR2D_H
#define GAME_VECTOR2D_H


class Vector2D {
private:
    int x;
    int y;
public:
    explicit Vector2D(int x = 0.0f, int y = 0.0f);

    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);

    void add(const int x, const int y);

    //Methods for the various math operations:
    void add(const Vector2D& vector);
    void subtract(const Vector2D& vector);
    void multiply(const int& scalar);
    void divide(const int& scalar);

    //overriding the operators
    Vector2D operator+(const Vector2D& right);
    Vector2D operator-(const Vector2D& right);
    Vector2D operator*(const int& scalar);
    Vector2D operator/(const int& scalar);

    //we also want to override the +=, -=, ... operators
    Vector2D& operator+=(const Vector2D& vector);
    Vector2D& operator-=(const Vector2D& vector);
    Vector2D& operator*=(const int& scalar);
    Vector2D& operator/=(const int& scalar);

    Vector2D& setToZero();
};


#endif //GAME_VECTOR2D_H

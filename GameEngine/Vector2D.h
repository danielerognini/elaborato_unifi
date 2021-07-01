#ifndef GAME_VECTOR2D_H
#define GAME_VECTOR2D_H


class Vector2D {
public:
    explicit Vector2D(const int& x = 0, const int& y = 0);
    static Vector2D toCartesian(const double& radius = 0.0, const double& angle = 0.0);
    
    void setVector(const int& x, const int& y);

    const int& getX() const;
    void setX(const int& x);
    const int& getY() const;
    void setY(const int& y);

    void add(const int& x, const int& y);
    void subtract(const int& x, const int& y);

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
    double operator%(Vector2D& right);

    //we also want to override the +=, -=, ... operators
    Vector2D& operator+=(const Vector2D& vector);
    Vector2D& operator-=(const Vector2D& vector);
    Vector2D& operator*=(const int& scalar);
    Vector2D& operator/=(const int& scalar);

private:
    int x;
    int y;
};


#endif //GAME_VECTOR2D_H

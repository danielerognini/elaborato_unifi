#ifndef GAME_VECTOR2D_H
#define GAME_VECTOR2D_H

class Vector2D {
public:
    explicit Vector2D(int x = 0, int y = 0);
    static Vector2D toCartesian(double radius = 0.0, double angle = 0.0);
    
    void setVector(int x, int y);
    
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    
    void add(int x, int y);
    void subtract(int x, int y);
    
    //Methods for the various math operations:
    void add(const Vector2D& vector);
    void subtract(const Vector2D& vector);
    void multiply(const int& scalar);
    void divide(const int& scalar);
    
    //overriding the operators
    Vector2D operator+(const Vector2D& right) const;
    Vector2D operator-(const Vector2D& right) const;
    Vector2D operator*(int scalar) const;
    Vector2D operator/(int scalar) const;
    double operator%(Vector2D& right);
    
    //we also want to override the +=, -=, ... operators
    Vector2D& operator+=(const Vector2D& vector);
    Vector2D& operator-=(const Vector2D& vector);
    Vector2D& operator*=(int scalar);
    Vector2D& operator/=(int scalar);
    
    bool operator==(const Vector2D& vector) const;

private:
    int x;
    int y;
};

#endif //GAME_VECTOR2D_H

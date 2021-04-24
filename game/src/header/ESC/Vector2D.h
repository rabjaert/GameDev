#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>|

class Vector2D
{
public:
	
	float xPos;
	float yPos;
	
	Vector2D();
	Vector2D(float x, float y);
	
	Vector2D& Add(const Vector2D& vec);
	Vector2D& Substract(const Vector2D& vec);
	Vector2D& Multiplay(const Vector2D& vec);
	Vector2D& Divide(const Vector2D& vec);

	//friend Vector
	friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
	Vector2D& operator/=(const Vector2D& vec);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& vec);

};



#endif VECTOR2D_H

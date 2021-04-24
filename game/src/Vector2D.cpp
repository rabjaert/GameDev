#include "header/ESC/Vector2D.h"


Vector2D::Vector2D()
{
	xPos = 0.0f;
	yPos = 0.0f;
}

Vector2D::Vector2D(float x, float y)
{
	this->xPos = x;
	this->yPos = y;
}

Vector2D& Vector2D::Add(const Vector2D& vec)
{
	this->xPos += vec.xPos;
	this->yPos += vec.yPos;

	return *this;
}

Vector2D& Vector2D::Substract(const Vector2D& vec)
{
	this->xPos -= vec.xPos;
	this->yPos -= vec.yPos;

	return *this;
}

Vector2D& Vector2D::Multiplay(const Vector2D& vec)
{
	this->xPos *= vec.xPos;
	this->yPos *= vec.yPos;

	return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& vec)
{
	this->xPos /= vec.xPos;
	this->yPos /= vec.yPos;

	return *this;
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
	return v1.Add(v2);
}
Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
	return v1.Substract(v2);
}
Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
	return v1.Multiplay(v2);
}
Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
	return v1.Multiplay(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
	return this->Add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
	return this->Substract(vec);
}

Vector2D& Vector2D::operator*=(const Vector2D& vec)
{
	return this->Multiplay(vec);
}

Vector2D& Vector2D::operator/=(const Vector2D& vec)
{
	return this->Divide(vec);
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec)
{
	stream << "(" << vec.xPos << "," << vec.yPos << ")";
	return stream;
}
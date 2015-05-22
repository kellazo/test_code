#include <math.h>
#include "Point2D.h"



	//Constructor
	cPoint2D::cPoint2D() { x = y = 0.0f; }

	cPoint2D::cPoint2D(float _x, float _y)
	{
		x = _x; y = _y;
	}

	//Operators
	cPoint2D cPoint2D::operator+ (const cPoint2D& a) const
	{
		cPoint2D tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;
		return tmp;
	}

	cPoint2D cPoint2D::operator+= (const cPoint2D& a)
	{
		x += a.x;
		y += a.y;
		return (*this);
	}

	cPoint2D cPoint2D::operator- (const cPoint2D& a) const
	{
		cPoint2D tmp;
		tmp.x = x - a.x;
		tmp.y = y - a.y;
		return tmp;
	}

	cPoint2D cPoint2D::operator-= (const cPoint2D& a)
	{
		x -= a.x;
		y -= a.y;
		return (*this);
	}

	 cPoint2D cPoint2D::operator= (const cPoint2D& a)
	{
		x = a.x;
		y = a.y;
		return (*this);
	}

	bool cPoint2D::operator== (const cPoint2D& a) const
	{
		return (x == a.x && y == a.y);
	}

	bool cPoint2D::operator!= (const cPoint2D& a) const
	{
		return (x != a.x || y != a.y);
	}

	//Methods
	cPoint2D cPoint2D::Set(const float _x, const float _y)
	{
		x = _x;
		y = _y;
		return (*this);
	}

	void cPoint2D::SetToZero()
	{
		x = y = 0.0f;
	}

	bool cPoint2D::IsZero() const
	{
		return x == 0.0f && x == 0.0f;
	}

	void cPoint2D::Negate()
	{
		x = -x; y = -y;
	}

	float cPoint2D::Distance(const cPoint2D& a) const
	{
		return hypot( (x - a.x),  (y - a.y) );
	}
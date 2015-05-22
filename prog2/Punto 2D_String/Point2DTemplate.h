#ifndef __cPoint2DTemplate__
#define __cPoint2DTemplate__

template <class TYPE>
class cPoint2DTemplate
{
public:

	TYPE x, y;

	//Constructor
	cPoint2DTemplate() { x = y = 0; }

	cPoint2DTemplate(TYPE _x, TYPE _y)
	{
		x = _x; y = _y;
	}

	//Operators
	cPoint2DTemplate operator+ (const cPoint2DTemplate& a) const
	{
		cPoint2DTemplate tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;
		return tmp;
	}

	cPoint2DTemplate operator+= (const cPoint2DTemplate& a)
	{
		x += a.x;
		y += a.y;
		return (*this);
	}

	cPoint2DTemplate operator- (const cPoint2DTemplate& a) const
	{
		cPoint2DTemplate tmp;
		tmp.x = x - a.x;
		tmp.y = y - a.y;
		return tmp;
	}

	cPoint2DTemplate operator-= (const cPoint2DTemplate& a)
	{
		x -= a.x;
		y -= a.y;
		return (*this);
	}

	cPoint2DTemplate operator= (const cPoint2DTemplate& a)
	{
		x = a.x;
		y = a.y;
		return (*this);
	}

	bool operator== (const cPoint2DTemplate& a) const
	{
		return (x == a.x && y == a.y);
	}

	bool operator!= (const cPoint2DTemplate& a) const
	{
		return (x != a.x || y != a.y);
	}

	//Methods
	cPoint2DTemplate Set(const TYPE _x, const TYPE _y)
	{
		x = _x;
		y = _y;
		return (*this);
	}

	void SetToZero()
	{
		x = y = 0;
	}

	bool IsZero() const
	{
		return x == 0 && x == 0;
	}

	void Negate()
	{
		x = -x; y = -y;
	}

	TYPE Distance(const cPoint2DTemplate& a) const
	{
		return hypot((x - a.x), (y - a.y));
	}

};

#endif //__cPoint2DTemplateTemplate__
#ifndef __cPoint2D__
#define __cPoint2D__

class cPoint2D
{
public:
	float x, y;

public:
	//Constructor
	cPoint2D();

	cPoint2D(float, float);

	//Operators
	cPoint2D operator+ (const cPoint2D&) const;

	cPoint2D operator+= (const cPoint2D&);

	cPoint2D operator- (const cPoint2D&) const;

	cPoint2D operator-= (const cPoint2D&);

	cPoint2D operator= (const cPoint2D&);

	bool operator== (const cPoint2D&) const;

	bool operator!= (const cPoint2D&) const;

	//Methods
	cPoint2D Set(const float, const float);

	void SetToZero();

	bool IsZero() const;

	void Negate();

	float Distance(const cPoint2D&) const;

};

#endif //__cPoint2D__
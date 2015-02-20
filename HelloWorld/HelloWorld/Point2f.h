#ifndef __Point2f_H__
#define __Point2f_H__ //variables de preprocessador

class Point2f
{
public:

	//Constructor
	//Point2f();

	void setZero()
	{
		x = y = 0.0f;
	}

	bool isZero() const //comproba si x o y es 0. 
	{
		return x == 0.f && y == 0.f; //una evaluacio sempre es una comprobacio per tant et retornara un 0 o un 1. un bolea
	}
	//fer un moteode que possi en negatiu el punt
	void Negate()
	{
		x = -x;
		y = -y; //que pasa si es negatiu, i si es un negatiu el posara a positiu? provao
	}

	/*Point2f operator+ (const Point2f& a) const  //retorno objecte delcarar operador +,-,*,%, no es modifiquin el a , referencia constant a, la operacio es constant pk em demanen que torni la suma de jo mes algu, no cambio jo mateix nomes tonru algun resultat.
	{
		Point2f tmp; //crea un objecte temporal el punt que contindra la suma de jo i el k man pasat

		tmp.x = x + a.x;
		tmp.y = y + a.y;

		return tmp; //despres retornu el objecte temporal k e creat pk el ki vulgui el faci servir.
	}*/

	Point2f& operator+= (const Point2f& a)
	{
		x += a.x;
		y += a.y;

		return(*this); //this es un punter a la clase
	}

	//suma resta multiplicar i dividir
	/*//Destructor
	virtual ~Point2f()
	{

	}*/


public:

	float x, y;
};

#endif //__Point2f_H__
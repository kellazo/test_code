#ifndef String_H
#define String_H //variables de preprocessador

#include <Windows.h>
#include <stdio.h>

class String
{
public:

	

	//3 constructors
	 String()
	{
		tamany = 1;
		cadena = new char[tamany];
		cadena[0] = '\0';
	}

	 String(const char* c)
	 {
		 tamany = strlen(c) + 1;
		 cadena = new char[tamany];
		 strcpy_s(cadena, tamany, c);
	 }



	 String(const String&);

	 ~String()
	 {
		 delete cadena;
	 }
	 
	

public:
	//propietats(atributs)
	char* cadena; //mai surt de rang
	int tamany;
	
	
};
#endif //__String_H__
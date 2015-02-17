#include <windows.h> //ha de ser el primer include de tots si porgramem amb visual studio i en windows
#include <assert.h>
#include <string.h>
#include <stdio.h>


class exemple
{
	//int valor;

	const int valor;

	exemple() : valor(15) //les propietats duna classe es construeixen en aquest punt en C //constructor// mateix nom que la clase
	{
		//valor = 15;
	}

	public:

	void SetValor(int v)
	{
		//valor = v;
	}

	int GetValor() //const  es una manera dasegurarte de les coses com tu son han de ser. que no es modifica, un codi que es const -correct es que tots els metodes no es modifiquen
	{
		return valor;
	}

	/*int GetValor() 
	{
	return valor++;
	}*/

};


//funcio output debug stream

void Log(char* cadena)
{
	assert(cadena);
	OutputDebugString(cadena);
}

void SetString(char* p)
{
	//assert(p != NULL); //aseegurat que p es diferent de NULL
	
	if (p != NULL )  //null sempre es fa servir per punters
		strcpy_s(p, 100, "hola mundo");
}

void PrintFloat(char* pcadena, float valor)
{
	
		assert(pcadena);
		//assert(valor >= 100.0f && valor <= 500.0f);

		float f = 100.0f;
		sprintf_s(pcadena, 100, "%f", valor);

}

int main(int argc, char** argv)
{
	//int a = argc;

	//assert(a != 1);1

	//char cadena[100];
	char cadena[100];
	PrintFloat(cadena, 3.1416f);

	//char* pepito = NULL;

	//SetString(cadena);
	//SetString(pepito);

	printf("%s", cadena);


	char textura[100] = "my textura.png";

	//char * const p = &textura[5];

	// expressio incorrecte pk p es const i no pot modificar p = &textura[6];

	const char * p = &textura[5];
	//es queixa pk vol cambiar el contingut
	strcpy_s(p, 100, "hola");

	char output[500];

	sprintf_s(output, 500, "cargando Textura: %s", textura);

	
	Log("hola mundo");
	Log(output);

	//Log("cargando Textura: %s en %f segundos", textura, 3.1415); fer aixo per deures i ha de ser un const char
	getchar();
	//posar const depsres de lasterisc la direccio que hi ha en aquell punter no es pot modificar, es a dir C=&cadena no funciona i posar const abans o sigui davant de tot no funciona strcpy(c, "hola"), el contingut no es modifica pero si la direccio.
	//strcpy()

}
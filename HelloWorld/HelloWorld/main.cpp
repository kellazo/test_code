#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) // unsign sense signe  tipus basics de C i rangs de valors
//quan ocupa un punter depen del tamañ de la memoria dreccionable. de la arquitectura si es 32 o 64 bytes.
//un char ocupa un byte

//punter es un char* es una direccio d ememoria que apunta a algun lloc
// un char** es un punter que apunta a un punter que et troba una direccio de memoria
//perque ho fem servir? 
//argc conte un 1 el primer element duna llista darguments es el primer programa que sexecuta
//argv conte un arrays de arrays de chars, conte els arguments de varis arguments amb char
//com fas varies cadenes doncs amb un char* com guardes una llista de char* amb char**
// es com char argc[ò][ò]; i char argc[`1][`0]; es com una taula.
{
	char c[10] = "hola";
	//char cc = 'R';
	//printf("%s", &cc);

	/*char c[0] = 'h';
	char c[1] = 'o';
	char c[2] = 'l';
	char c[3] = 'a';
	char c[4] = '\0';*/
	printf("%s", &c[1]);
	//char*pc = &c;
	//printf("%s", pc);
	//printf("%s", c);
	//getchar();
	//return 0;
}
//code snippets manager visual studio

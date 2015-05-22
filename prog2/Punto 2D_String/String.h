#include <string.h>
#include <stdarg.h>
#define TMP_STRING_SIZE 4096

#ifndef __cSTRING__
#define __cSTRING__

class cString
{

private:
	char* myString;
	unsigned int size;
public:

	////////////////
	//Constructors//
	////////////////

	cString();
	
	cString(const cString&);

	cString(const char* format, ...);

	//////////////
	//Destructor//
	//////////////

	~cString();

	///////////
	//Métodes//
	//////////

	void Alloc(int);

	void Clear();

	unsigned int Len() const;

	int Capacity() const;

	const char* GetString() const;

	void Trim(bool trimStart = true, bool trimEnd = true, char toRemove = ' ');

	int Replace(const char* toErase, const char* toInsert);

	/////////////
	//Operadors//
	/////////////

	bool operator== (const cString&) const;

	bool operator== (const char*) const;

	bool operator!= (const cString&) const;

	bool operator!= (const char*) const;
	
	cString operator= (const char*);

	cString operator= (const cString&);

	const cString operator+= (const char*);

	const cString operator+= (const cString&);

};

#endif //__cSTRING__
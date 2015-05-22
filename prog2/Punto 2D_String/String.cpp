#include "String.h"
#include <stdio.h>

cString::cString()
{
	Alloc(1);
	strcpy_s(myString, size, "");
}

cString::cString(const cString& cRecieved)
{
	Alloc(cRecieved.Len() + 1);
	strcpy_s(myString, size, cRecieved.GetString());
}

cString::cString(const char* format, ...)
{
	size = 0;

	if (format != NULL)
	{
		static char tmp[TMP_STRING_SIZE];
		static va_list ap;

		//Construir la myString a partir dels arguments variables
		va_start(ap, format);
		int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
		va_end(ap);

		if (res > 0)
		{
			Alloc(res + 1);
			strcpy_s(myString, size, tmp);
		}
	}
	if (size == 0)
	{
		Alloc(1);
		Clear();
	}
}

//////////////
//Destructor//
//////////////

cString::~cString()
{
	if (myString)
	{
		delete[] myString;
	}
}

///////////
//Métodes//
//////////

void cString::Alloc(int res)
{
	size = res;
	myString = new char[size];
}

void cString::Clear()
{
	if (myString != NULL)
	{
		delete[] myString;
		Alloc(1);
		strcpy_s(myString, size, "");
	}
}

unsigned int cString::Len() const
{
	return strlen(myString);
}

int cString::Capacity() const
{
	return size;
}

const char* cString::GetString() const
{
	return myString;
}

void cString::Trim(bool trimStart, bool trimEnd, char toRemove)
{
	int n = 0;
	int m = Len();
	while (myString[n] == toRemove && n < Len() && trimStart == true)
	{
		n++;
	}
	while (myString[m - 1] == toRemove && m >= 0 && trimEnd == true)
	{
		m--;
	}
	for (int p = 0; p <= m - n - 1; p++)
	{
		myString[p] = myString[p + n];
	}
	myString[m - n] = '\0';
}


int  cString::Replace(const char* toErase, const char* toInsert)
{
	int nOfReplacements = 0;
	if (toErase != NULL)
	{
		int sizeDifference = 0;
		int toEraseLen = strlen(toErase);
		int toInsertLen = strlen(toInsert);
		//Getting how much we'll have to move the characters after the substitution
		sizeDifference = toEraseLen - toInsertLen;
		
		for (int n = 0; n < strlen(myString); n++)
		{
			int counter = 0;
			//Comparing our string to the characters to substitute
			for (int m = 0; m < toEraseLen && myString[n + m] == toErase[m]; m++)
			{    counter++;    }

			//Moving the characters following our replacement
			if (counter >= toEraseLen)
			{
				if (sizeDifference > 0)
				{
					for (int m = toInsertLen; m + n + sizeDifference <= strlen(myString); m++)
					{
						myString[m + n] = myString[m + n + sizeDifference];
					}
				}
				else if (sizeDifference < 0)
				{
					if (strlen(myString) - sizeDifference >= size)
					{
						cString tmp(*this);
						Alloc(size - sizeDifference + 1);
						strcpy_s(myString, tmp.size, tmp.myString);
					}
					for (int m = strlen(myString); m >= n + toEraseLen; m--)
					{
						myString[m - sizeDifference] = myString[m];
					}
				}
				//Replacing the word
				for (int m = 0; m < toInsertLen; m++)
				{
					myString[m + n] = toInsert[m];
				}
				nOfReplacements++;
				n += toInsertLen;
			}
		}
	}
	return nOfReplacements;
}


/////////////
//Operadors//
/////////////

bool cString::operator== (const cString& string) const
{
	return strcmp(string.myString, myString) == 0;
}

bool cString::operator== (const char* string) const
{
	if (string != NULL)
	{
		return strcmp(string, myString) == 0;
	}
	return false;
}

bool cString::operator!= (const cString& string) const
{
	return strcmp(string.myString, myString) != 0;
}

bool cString::operator!= (const char* string) const
{
	if (string != NULL)
	{
		return strcmp(string, myString) != 0;
	}
	return false;
}


cString cString::operator= (const char* string)
{
	if (string != NULL)
	{
		if (strlen(string) + 1 > size)
		{
			delete[] myString;
			Alloc(strlen(string) + 1);	
		}
		strcpy_s(myString, size, string);
	}
	else
	{
		Clear();
	}
	return(*this);
}

cString cString::operator= (const cString& string)
{
	if (string.myString != NULL)
	{
		if (string.Len() + 1 > size)
		{
			delete[] myString;
			Alloc(string.Len() + 1);
		}
		strcpy_s(myString, size, string.myString);
	}
	else
	{
		Clear();
	}

	return(*this);
}

const cString cString::operator+= (const char* string)
{
	if (string != NULL)
	{
		cString tmp(*this);
		delete[] myString;
		Alloc(strlen(string) + size);
		strcpy_s(myString, tmp.size, tmp.myString);
		strcat_s(myString, size, string);
	}
	return(*this);
}

const cString cString::operator+= (const cString& string)
{
	if (string.myString != NULL)
	{
		cString tmp(*this);
		delete[] myString;
		Alloc(strlen(string.myString) + size);
		strcpy_s(myString, tmp.size, tmp.myString);
		strcat_s(myString, size, string.myString);
	}
	return(*this);
}


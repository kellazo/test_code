

template <class DATYPE> class DynamicArray
{

private:
	DATYPE *data;
	unsigned int capacity; //allocated memory
	unsigned int size; //number of elements

	void reallocate(unsigned const int capacity) //nueva capacidad
	{	//guardamos temporalmente data en una variable tmp
		DATYPE *tmp = data;
		//eliminamos data
		delete[] data;
		//ponemos nueva data con la nueva capacidad
		DATYPE *data[capacity];
		//cpy tmp en data nueva
		
		for (int i = 0; i < size; i++)
		{
			data[i] = tmp[i];

		}
		//cambia la capacidad propia por la nueva capacidad
		this->capacity = capacity;
		//borrem tmp pk ja no el necessitem i alliberem memoria
		delete tmp;
	}


public:
	//constructores
	DynamicArray()
	{
		DATYPE *data[1];
		capacity = 1;
		size = 0;
	}

	DynamicArray(unsigned const int capacity)
	{
		DATYPE *data[capacity];
		this->capacity = capacity; // es el capacity de la class
		size = 0;
	}

	//destructor
	~DynamicArray(){cout<<Array Borrado}


	//Add element at the end
	void push_back(const DATYPE val)
	{ 
		if (val == NULL)
		{
			return;
		}
		if (size >= capacity)
		{
			reallocate(capacity + 1);
		}
		data[size] = val;
		size++;
		
		


	}
	






};













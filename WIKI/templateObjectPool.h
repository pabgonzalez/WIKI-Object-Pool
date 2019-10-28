#include <iostream>
#include <vector>

using namespace std;

template <typename T, int N> class ObjectPool				//N es el número de objetos T que tendrá el pool
{
private:
	ObjectPool();											//constructor privado pues ObjectPool es un singleton
	inline static ObjectPool<T, N>* singleton = nullptr;	//guarda el único pool de N objetos de tipo T.

	T object[N];			//arreglo de objetos T
	vector<bool> isFree;	//vector asociado al arreglo de objetos, indicando si está o no libre

public:
	inline static ObjectPool<T,N>* getPool(void)	//función estática para obtener la única instancia del objectPool
	{
		if (singleton == nullptr)
		{
			singleton = (ObjectPool *) ::new ObjectPool<T, N>;
		}
		return singleton;
	}
	T* getObject(void);		//devuelve un objeto de tipo T si hay alguno libre
	void storeObject(T*);	//guarda en el pool un objeto que ya no se está usando

};

template <typename T, int N> ObjectPool<T, N>::ObjectPool()
	: isFree(N, true) //todos libres al principio
{}

template <typename T, int N> 
T* ObjectPool<T, N>::getObject(void)
{
	for (int i = 0; i < N; i++)		//revisa todos los objetos
	{
		if (isFree[i] == true)		//si encuentra uno libre
		{
			isFree[i] = false;		//lo ocupa
			return object + i;		//y lo entrega
		}
	}
	return nullptr;					//devuelve null si no hay ninguno libre
}

template <typename T, int N> 
void ObjectPool<T, N>::storeObject(T* obj)
{
	for ( int i = 0; i < N; i++ )	//revisa todos los objetos
	{
		if (obj == (object+i) )		//si lo encuentra
		{
			isFree[i] = true;		//lo libera
		}
	}
}


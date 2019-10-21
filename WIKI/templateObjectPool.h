#include <iostream>
#include <vector>

using namespace std;

template <typename T> class ObjectPool	//N goes for number of objets
{
private:
	static ObjectPool<T>* singleton = nullptr;
	ObjectPool(int N);	//constructor privado
	T* list;
	vector<bool> free;
	unsigned size;

public:
	~ObjectPool();
	inline static ObjectPool<T>* getPool()
	{
		if (singleton == nullptr)
		{
			singleton = (ObjectPool) ::new ObjectPool<T>;
		}
		return singleton;
	}
	T* getObject(void);
	void storeObject(T*);

};

template <typename T> ObjectPool<T>::ObjectPool(int N)
	: free(N,true)		//todos libres
{
	list = ::new T[N];		
	size = N;
}

template <typename T> ObjectPool<T>::~ObjectPool()
{
	::delete[] list;
}

template <typename T> T* ObjectPool<T>::getObject(void)
{
	for (unsigned i = 0; i < size; i++ )
	{
		if (free[i] == true)
		{
			free[i] = false;
			return list+i;
		}
	}
	return nullptr;
}

template <typename T> void ObjectPool<T>::storeObject(T* obj)
{
	for (unsigned i = 0 ; i < size; i++ )
	{
		if (obj == list+i)
		{
			free[i] = true;
		}
	}
}
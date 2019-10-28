#include <iostream>
#include <iomanip>
#include "templateObjectPool.h"

using namespace std;

class Bullet
{
public:
	int16_t speed;
	uint32_t color; //RGBA
};

int main(void)
{
	cout << "___BULLET EXAMPLE___" << endl;
	ObjectPool<Bullet, 3>* myPool = ObjectPool<Bullet, 3>::getPool();

	Bullet* b1 = myPool->getObject();
	Bullet* b2 = myPool->getObject();
	Bullet* b3 = myPool->getObject();
	Bullet* b4 = myPool->getObject();	//limite excedido

	b1->speed = 100;
	b2->speed = 200;
	b3->speed = 300;
	b1->color = 0xff000000;	//red
	b2->color = 0x00ff0000;	//green
	b3->color = 0x0000ff00;	//blue

	cout << '\t' << "Speed" << '\t' << "Color" << endl;
	cout << "b1" << '\t' << dec << b1->speed << '\t' << hex << uppercase << setfill('0') << setw(8) << b1->color << endl;
	cout << "b2" << '\t' << dec << b2->speed << '\t' << hex << uppercase << setfill('0') << setw(8) << b2->color << endl;
	cout << "b3" << '\t' << dec << b3->speed << '\t' << hex << uppercase << setfill('0') << setw(8) << b3->color << endl;
	cout << "b4 is null pointer: " << b4 << endl;

	cout << endl;

	myPool->storeObject(b1);	//devuelvo b1
	myPool->storeObject(b2);	//devuelvo b2
	myPool->storeObject(b3);	//devuelve b3
	

	ObjectPool<Bullet, 3>* otherPoolx3 = ObjectPool<Bullet, 3>::getPool();	//pido un pool de 3 Bullets
	ObjectPool<Bullet, 6>* pool1x6 = ObjectPool<Bullet, 6>::getPool();	//pido un pool de 6 Bullets
	ObjectPool<Bullet, 6>* pool2x6 = ObjectPool<Bullet, 6>::getPool();	//pido otro pool de 6 Bullets
	cout << "myPool: "  << '\t' << myPool << endl;
	cout << "otherPoolx3: " << '\t' << otherPoolx3 << endl;
	cout << "pool1x6: " << '\t' << pool1x6 << endl;
	cout << "pool2x6: " << '\t' << pool2x6 << endl;
}
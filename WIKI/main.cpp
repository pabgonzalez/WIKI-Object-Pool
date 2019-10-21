#include "templateObjectPool.h"

class Bullet
{
public:
	Bullet()
	{
		speed = 120;
		color = 0xFF000000;	//RGBA
	}
	int speed;
	uint32_t color;
};

int main(void)
{
	ObjectPool<Bullet>* myPool = ObjectPool<Bullet>::getPool();

	Bullet* myBullet = myPool->getObject();
	cout << "Speed of MyBullet: " << myBullet->speed << endl;
	cout << "Color of MyBullet: " << hex << uppercase << myBullet->color << endl;
	myPool->storeObject(myBullet);
	cout << "Speed of MyBullet: " << myBullet->speed << endl;
	cout << "Color of MyBullet: " << hex << uppercase << myBullet->color << endl;

	//ObjectPool<Bullet>* otherPool = ObjectPool<Bullet>::getPool();
	//cout << "myPool: "  << myPool << endl;
	//cout << "otherPool: " << otherPool << endl;
}
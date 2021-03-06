#include "dscene.h"  
#include <cmath>


DScene::DScene(void)
{
	collisionListX = new QList<collisionObj*>;
	collisionListY = new QList<collisionObj*>;
	jumpObjList = new QList<collisionObj*>;
	sceneList = new QList<DScene*>;
	coupleList = new QList<spxGame::collisionCouple*>;
}

DScene::DScene(QList<collisionObj*> *XL, QList<collisionObj*> *YL)
{
	collisionListX = XL;
	collisionListY = YL;
	collisionListX = new QList<collisionObj*>;
	collisionListY = new QList<collisionObj*>;
	jumpObjList = new QList<collisionObj*>;
	sceneList = new QList<DScene*>;
	coupleList = new QList<spxGame::collisionCouple*>;
}


DScene::~DScene(void)
{
	for (auto i : *collisionListX)
	{
		i->~collisionObj();
	}
	for (auto i : *collisionListY)
	{
		i->~collisionObj();
	}
	for (auto i : *jumpObjList)
	{
		i->~collisionObj();
	}
	for (auto i : *coupleList)
	{
		i->~collisionCouple();
	}
}


void DScene::run()
{
	collisionTest();//计算碰撞，并触发
	doTrigger();//全局判断函数
	spxGame::sortObj(collisionListX, collisionListY);
}


void DScene::collisionTest()
{
	collisionObj *obj1;
	collisionObj *obj2;

	QList<spxGame::collisionCouple*> coupleListX;
	QList<spxGame::collisionCouple*> coupleListY;
	for(auto iter1 = collisionListX->begin(); iter1 != collisionListX->end(); ++iter1)
	{
		obj1 = *iter1;
		for (auto iter2 = (iter1 + 1); iter2 != collisionListX->end(); ++iter2)
		{
			obj2 = *iter2;
			if(obj1 == obj2)
				continue;
			if(abs(obj1->x() - obj2->x()) < obj1->Width())
				coupleListX << new spxGame::collisionCouple(obj1, obj2);
			else
				break;
		}
	}

	for(auto iter1 = collisionListY->begin(); iter1 != collisionListY->end(); ++iter1)
	{
		obj1 = *iter1;
		for (auto iter2 = (iter1 + 1); iter2 != collisionListY->end(); ++iter2)
		{
			obj2 = *iter2;
			if(obj1 == obj2)
				continue;
			if(abs(obj1->y() - obj2->y()) < obj1->Height())
				coupleListY << new spxGame::collisionCouple(obj1, obj2);
			else
				break;
		}
	}
	//取出所有x，y区间重叠的对象
//	while((!collisionListX->isEmpty()) && (!collisionListY->isEmpty()))
	{
		spxGame::collisionCouple *temp1;
		spxGame::collisionCouple *temp2;
		for(auto iter1 = coupleListX.begin(); iter1 != coupleListX.end(); ++iter1)
		{
			temp1 = *iter1;
			for (auto iter2 = coupleListY.begin(); iter2 != coupleListY.end(); ++iter2)
			{
				temp2 = *iter2;
				if(*temp1 == *temp2)
				{
					*coupleList << temp1;
					temp1->collisionTrigger();
					coupleListY.erase(iter2);
					break;
				}
			}
			if(collisionListY->isEmpty())
				break;
		}
		temp1->~collisionCouple(); temp2->~collisionCouple();//防泄漏
	}
	//将x区间重叠同时y区间也重叠的对象对加入链表,并直接触发碰撞事件
}

void DScene::doTrigger()
{
	for (auto iter = collisionListX->begin(); iter != collisionListX->end(); ++iter)
	{
		auto temp = *iter;
		temp->trigger();
	}
}

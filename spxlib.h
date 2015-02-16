#pragma once
#ifndef SPXLIB_H
#define SPXLIB_H

#include <qlist.h>
#include "header\collisionObj.h"

namespace spxGame
{
	void insertObj(QList<collisionObj*> *objListX, QList<collisionObj*> *objListY, collisionObj *obj);//索引,并给对象传入链表指针
	void sortObj(QList<collisionObj*> *objListX, QList<collisionObj*> *objListY);
	void delObj(QList<collisionObj*> *objListX, QList<collisionObj*> *objListY, collisionObj *obj);

	class collisionCouple
	{
	public:
		explicit collisionCouple(collisionObj* one, collisionObj* two){ first = one; second = two; }
		const collisionObj* firstObj(){ return first; }
		const collisionObj* secondObj(){ return second; }

		bool operator == (collisionCouple temp){
			return ((first == temp.firstObj()) && (second == temp.secondObj()))
				|| ((first == temp.secondObj()) && (second == temp.firstObj()));
		}

		void collisionTrigger(){ first->collisionTrigger(second->id()); second->collisionTrigger(first->id()); }
	private:
		collisionObj* first;
		collisionObj* second;
	};
}

void spxGame::delObj(QList<collisionObj*> *objListX, QList<collisionObj*> *objListY, collisionObj *obj)
{
	for (auto i = objListX->begin();i != objListX->end(); ++i)
	{
		for (auto i = objListY->begin(); i != objListX->end(); ++i)
		{
			if (*i == obj)
			{
				objListY->erase(i);
				break;
			}
		}
		if (*i == obj)
		{
			objListX->erase(i);
			break;
		}
	}
	spxGame::sortObj(objListX, objListY);
}
void spxGame::insertObj(QList<collisionObj*> *objListX, QList<collisionObj*> *objListY, collisionObj *obj)
{
	//insert x
	if (objListX->isEmpty() || obj->x() >= objListX->last()->x())	//判断末尾跳判定
	{
		objListX->append(obj);
	}
	else
	{
		for (auto i = objListX->begin(); i != objListX->end(); ++i)
		{
			if ((*i)->x() >= obj->x())
			{
				objListX->insert(i, obj);
				break;
			}
		}
	}
	//insert y
	if (objListY->isEmpty() || obj->y() >= objListY->last()->y())	//判断末尾跳判定
	{
		objListY->append(obj);
	}
	else
	{
		for (auto i = objListY->begin(); i != objListY->end(); ++i)
		{
			if ((*i)->y() >= obj->y())
			{
				objListY->insert(i, obj);
				break;
			}
		}
	}
}

void spxGame::sortObj(QList<collisionObj*> *objListX, QList<collisionObj*> *objListY)
{
	//insert sort x
	for (auto i = objListX->begin() + 1 ; i != objListX->end(); ++i)
	{
		for (auto t = objListX->begin(); t != i; ++t)
		{
			if ((*t)->x() >= (*i)->x())
			{
				objListX->insert(t, *i);
				objListX->erase(i);
				--i;
				break;
			}
		}
	}
	//insert sort y
	for (auto i = objListY->begin() + 1; i != objListY->end(); ++i)
	{
		for (auto t = objListY->begin(); t != i; ++t)
		{
			if ((*t)->y() >= (*i)->y())
			{
				objListY->insert(t, *i);
				objListY->erase(i);
				--i;
				break;
			}
		}
	}
}
#endif
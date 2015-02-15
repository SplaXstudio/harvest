#pragma once

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
		explicit collisionCouple(collisionObj* one, collisionObj* two){first = one; second = two;}
		const collisionObj* firstObj(){return first;}
		const collisionObj* secondObj(){return second;}

		bool operator == (collisionCouple temp){return ((first == temp.firstObj()) && (second == temp.secondObj()))
													|| ((first == temp.secondObj()) && (second == temp.firstObj()));}

		void collisionTrigger(){first->collisionTrigger(second->ID()); second->collisionTrigger(first->ID());}
	private:
		collisionObj* first;
		collisionObj* second;
	};
}
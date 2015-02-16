#include "spxlib.h"

void spxGame::delObj(QList<collisionObj*> *objListX, QList<collisionObj*> *objListY, collisionObj *obj)
{
	for (auto iter1 = objListX->begin(); iter1 != objListX->end(); ++iter1)
	{
		if (*iter1 == obj)
		{
			objListX->erase(iter1);
			break;
		}
	}
	for (auto iter2 = objListY->begin(); iter2 != objListY->end(); ++iter2)
	{
		//auto p = *iter2;		//test
		if (*iter2 == obj)
		{
			objListY->erase(iter2);
			break;
		}
	}
	spxGame::sortObj(objListX, objListY);
}
void spxGame::insertObj(QList<collisionObj*> *objListX, QList<collisionObj*> *objListY, collisionObj *obj)
{
	//insert x
	if (objListX->isEmpty() || obj->x() >= objListX->last()->x())	//ÅÐ¶ÏÄ©Î²ÌøÅÐ¶¨
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
	if (objListY->isEmpty() || obj->y() >= objListY->last()->y())	//ÅÐ¶ÏÄ©Î²ÌøÅÐ¶¨
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
	//QList<collisionObj*> *temp = new QList<collisionObj*>(*objListX);
	//objListX->clear();
	//insert sort x
	for (auto i = objListX->begin() + 1; i != objListX->end(); ++i)
	{
		for (auto t = objListX->begin(); t != i; ++t)
		{
			if ((*t)->x() >= (*i)->x())
			{
				collisionObj* temp = new collisionObj(*i);
				objListY->insert(t, temp);
				++i; ++t;
				objListY->erase(i);
				//continue;
				--i;
				break;
			}

		}
	}
	//insert sort y
	auto begin = objListY->begin();
	for (QList<collisionObj*>::iterator i = objListY->begin(); i != objListY->end(); ++i)
	{
		for (auto t = begin; t != i; ++t)
		{
			if ((*t)->y() > (*i)->y())
			{
				collisionObj* temp = new collisionObj(*i);
				objListY->insert(t, temp);
				++i; ++t;
				objListY->erase(i);
				//continue;
				--i;
				break;
			}
		}
	}
}
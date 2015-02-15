#pragma once

#include <qlist.h>
#include "spxlib.h"
#include "header\uncollisionObj.h"
#include "header\collisionObj.h"

class DScene
{
public:
	DScene(void);
	DScene(QList<collisionObj*>*, QList<collisionObj*>*);
	~DScene(void);

	void run();//场景主循环
	void collisionTest();

	
private:
	QList<collisionObj*> *collisionListX;
	QList<collisionObj*> *collisionListY;
	QList<uncollisionObj*> *uncollisionList;

	QList<collisionObj*> *jumpObjList;//场景跳转相关对象链表

	
public:		//unittest
	QList<spxGame::collisionCouple*> *coupleList;//碰撞对链表
private:	//unittest

	int id;
protected:
	void doTrigger();
};


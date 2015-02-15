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

	void run();//������ѭ��
	void collisionTest();

	
private:
	QList<collisionObj*> *collisionListX;
	QList<collisionObj*> *collisionListY;
	QList<uncollisionObj*> *uncollisionList;

	QList<collisionObj*> *jumpObjList;//������ת��ض�������

	
public:		//unittest
	QList<spxGame::collisionCouple*> *coupleList;//��ײ������
private:	//unittest

	int id;
protected:
	void doTrigger();
};


#pragma once

#include "spxlib.h"

class DScene
{
public:
	DScene(void);
	DScene(QList<collisionObj*>*, QList<collisionObj*>*);
	~DScene(void);

	void run();//������ѭ��
	
	void addItem(collisionObj*);
	void delItem(collisionObj*);
	
private:
	QList<collisionObj*> *collisionListX;
	QList<collisionObj*> *collisionListY;

	QList<collisionObj*> *jumpObjList;//������ת��ض�������
	QList<DScene*> *sceneList;
	
public:		//unittest
	QList<spxGame::collisionCouple*> *coupleList;//��ײ������
private:	//unittest

	int id;
protected:
	void doTrigger();
	void collisionTest();
	void tpTrigger();
};


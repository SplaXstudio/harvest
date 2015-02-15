#pragma once

#include <qlist.h>
#include "spxlib.h"
#include "header\uncollisionObj.h"

class DScene
{
public:
	DScene(void);
	~DScene(void);

	void run();//������ѭ��
	void collisionTest();

	
private:
	QList<collisionObj*> *collisionListX;
	QList<collisionObj*> *collisionListY;
	QList<uncollisionObj*> *uncollisionList;

	QList<collisionObj*> *jumpObjList;//������ת��ض�������

	QList<spxGame::collisionCouple*> *coupleList;//��ײ������

	int id;
protected:
	void doTrigger();
};


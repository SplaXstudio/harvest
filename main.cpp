#include "dscene.h"
#include <qdebug.h>

int main(int argc, char** argv)
{
	QList<collisionObj*> *Lx = new QList<collisionObj*>,
						 *Ly = new QList<collisionObj*>;
	for (double base = 0; base < 5; ++base)
	{
		collisionObj *temp = new collisionObj(base * 11, base * 11, 0, QPointF(20, 20));
		temp->setID((int)base);
		Lx->append(temp);
		Ly->append(temp);
	}

	DScene *scene = new DScene(Lx, Ly);

	scene->run();

	for (auto i : *scene->coupleList)
	{
		qDebug() << i->firstObj()->id()  
			<< " collision with " 
			<< i->secondObj()->id()
			<< "\n";
	}

	return 0;
}
/*
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
*/

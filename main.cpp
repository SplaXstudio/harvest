#include "dscene.h"
#include <qdebug.h>

int main(int argc, char** argv)
{
	QList<collisionObj*> *Xlist = new QList < collisionObj* >, *Ylist = new QList < collisionObj* > ;
	for (double i = 1; i <= 5; ++i)
	{
		collisionObj* temp = new collisionObj(i, 2 * i - 1, 0, QPointF(0, 0));
		spxGame::insertObj(Xlist, Ylist, temp);
	}

	qDebug() << "Xlist: \n";
	for (auto i : *Xlist)
	{
		qDebug() <<"x: " << i->x() << "y: " << i->y() << "\n";
	}
	qDebug() << "Ylist: \n";
	for (auto i : *Ylist)
	{
		qDebug() << "x: " << i->x() << "y: " << i->y() << "\n";
	}

	spxGame::sortObj(Xlist, Ylist);
	qDebug() << "-------sorted:------- \n";
	qDebug() << "Xlist: \n";
	for (auto i : *Xlist)
	{
		qDebug() << "x: " << i->x() << "y: " << i->y() << "\n";
	}
	qDebug() << "Ylist: \n";
	for (auto i : *Ylist)
	{
		qDebug() << "x: " << i->x() << "y: " << i->y() << "\n";
	}

	auto i = Xlist->begin() + 3;
	spxGame::delObj(Xlist, Ylist, *i);
	qDebug() << "-------deleted:------- \n";
	qDebug() << "Xlist: \n";
	for (auto i : *Xlist)
	{
		qDebug() << "x: " << i->x() << "y: " << i->y() << "\n";
	}
	qDebug() << "Ylist: \n";
	for (auto i : *Ylist)
	{
		qDebug() << "x: " << i->x() << "y: " << i->y() << "\n";
	}
	Xlist->clear();
	Ylist->clear();
	/*			Åö×²testunit
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
	*/
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

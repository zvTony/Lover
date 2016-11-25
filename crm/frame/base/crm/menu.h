#ifndef MENU_H
#define MENU_H

#include <QObject>

class crm;
class Menu : public QObject
{
	Q_OBJECT
public:
	Menu(QObject* parent = nullptr);
	virtual ~Menu();

public slots:
	void    onExit(bool);

};

#endif // !MENU_H

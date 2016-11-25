#ifndef LV_MENU_H
#define LV_MENU_H

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

#endif // !LV_MENU_H

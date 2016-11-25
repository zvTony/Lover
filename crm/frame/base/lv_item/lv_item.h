#ifndef LV_ITEM_H
#define LV_ITEM_H

#include "../../../include/header.h"

class LV_Item : public QObject
{
	Q_OBJECT
public:
	LV_Item(QObject* parent = nullptr);
	virtual ~LV_Item();

	int      rowCount();
	LV_Item* child(int index);
	QString  get_name(int index = 0)    { return QString(); }
private:
	QList<LV_Item*>*    m_pChild;

};

#endif // !LV_ITEM_H

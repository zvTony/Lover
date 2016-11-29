#ifndef LVITEM_CUSTOMER_H
#define LVITEM_CUSTOMER_H

#include "../lv_item.h"

class LvItem_Customer : public LV_Item
{
public:
	LvItem_Customer(LV_Item* item = nullptr, const QString& name = QString());
	virtual ~LvItem_Customer();

	QString  get_name(int index = 0)    { return m_name; }
	QString  get_title()                { return QStringLiteral("客户信息"); }
	bool     loadChild(const QString& viewName);

private:
	QString    m_name;

};


#endif // !LVITEM_CUSTOMER_H

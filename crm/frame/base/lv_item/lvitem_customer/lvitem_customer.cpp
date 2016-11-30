#include "lvitem_customer.h"
#include "../../../../include/header.h"

extern LV_DB*       g_pDB;
extern LV_UIManage* g_pUIManage;

LvItem_Customer::LvItem_Customer(LV_Item* item, const QString& name)
	:LV_Item(item), m_name(name)
{
	
}
LvItem_Customer::~LvItem_Customer()
{

}

bool LvItem_Customer::loadChild(const QString& viewName)
{
	auto sql = QString("select name from lv_customer;");
	auto ret = g_pDB->queryArray(sql);
	if (ret.size() < 1)
		return false;
	for (int i = 0; i < ret.size(); ++i)
	{
		QString name = ret[i];
		auto item = new LvItem_Customer(this, name);
		this->addChild(item);
	}

	return true;
}
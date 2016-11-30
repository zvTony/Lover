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
	auto name = ret[0];

	auto item = new LvItem_Customer(this, "test");
	
	this->addChild(item);

	return true;
}
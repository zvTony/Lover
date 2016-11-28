#include "lvitem_customer.h"

LvItem_Customer::LvItem_Customer(LV_Item* item, const QString& name)
	:LV_Item(item), m_name(name)
{

}
LvItem_Customer::~LvItem_Customer()
{

}

bool LvItem_Customer::loadChild(const QString& viewName)
{
	auto item = new LvItem_Customer(this, "test");
	
	this->addChild(item);

	return true;
}
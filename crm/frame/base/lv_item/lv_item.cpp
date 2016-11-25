#include "lv_item.h"

LV_Item::LV_Item(QObject* parent)
	:QObject(parent)
{
	m_pChild = new QList<LV_Item*>();
}
LV_Item::~LV_Item()
{
	qDeleteAll(m_pChild->begin(), m_pChild->end());
}

int LV_Item::rowCount()
{
	if (m_pChild)
	{
		return m_pChild->size();
	}
	return 0;
}

LV_Item* LV_Item::child(int index)
{
	if (m_pChild)
	{
		return m_pChild->at(index);
	}
	return nullptr;
}
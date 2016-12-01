#include <QVariant>
#include "lv_model.h"
#include "../lv_item/lv_item.h"

LV_Model::LV_Model(LV_Item* item, QObject* parent)
	:QAbstractItemModel(parent), m_pItem(item)
{

}

LV_Model::~LV_Model()
{

}

QVariant LV_Model::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();
	if (role == Qt::DisplayRole)
	{
		auto item = getItem(index);
		if (item)
			return item->get_name(index.column());
	}
	return QVariant();
}
QVariant LV_Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	return QAbstractItemModel::headerData(section, orientation, role);
}
QModelIndex LV_Model::index(int row, int column, const QModelIndex &parent) const
{
	if (parent.isValid() && parent.column() != 0)
		return QModelIndex();
	auto parentItem = getItem(parent);
	if (!parentItem)
		return QModelIndex();
	auto childItem = parentItem->child(row);
	if (childItem)
		return createIndex(row, column, childItem);
	return QModelIndex();
}
QModelIndex LV_Model::parent(const QModelIndex &index) const
{
	return QModelIndex();
}

int LV_Model::rowCount(const QModelIndex &parent) const
{
	auto item = getItem(parent);
	if (item)
	{
		item->loadChild();
		return item->rowCount();
	}
	return 0;
}
int LV_Model::columnCount(const QModelIndex &parent) const
{
	const int DEFAULT_COL_COUNT = 1;    //common tree style use
	return DEFAULT_COL_COUNT;
}

LV_Item* LV_Model::getItem(const QModelIndex& index) const
{
	if (index.isValid())
	{
		auto item = static_cast<LV_Item*>(index.internalPointer());
		if (item)
			return item;
	}
	return m_pItem;
}

Qt::ItemFlags LV_Model::flags(const QModelIndex &index) const
{
	auto item = getItem(index);
	if (item)
		return item->flags();
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}
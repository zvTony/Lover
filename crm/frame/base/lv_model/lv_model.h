#ifndef LV_MODEL_H
#define LV_MODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>

#include "../../../include/header.h"

class LV_Model : public QAbstractItemModel
{
	Q_OBJECT
public:
	LV_Model(LV_Item* item, QObject* parent = nullptr);
	virtual ~LV_Model();

public:
	QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
	QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
	QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
	QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;

	int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
	int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

	Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

private:
	LV_Item* getItem(const QModelIndex& index) const;

private:
	LV_Item*    m_pItem;
};


#endif // !LV_MODEL_H

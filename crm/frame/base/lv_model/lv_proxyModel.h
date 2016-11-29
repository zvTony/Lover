#ifndef LV_PROXYMODEL_H
#define LV_PROXYMODEL_H

#include <QSortFilterProxyModel>

class LV_ProxyModel : public QSortFilterProxyModel
{
public:
	LV_ProxyModel(QSortFilterProxyModel* parent = nullptr);
	virtual ~LV_ProxyModel();

public:

};


#endif // !LV_PROXYMODEL_H

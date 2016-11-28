#ifndef LV_PROXYMODEL_H
#define LV_PROXYMODEL_H

#include <QAbstractProxyModel> 

class LV_ProxyModel : public QAbstractProxyModel
{
public:
	LV_ProxyModel(QAbstractProxyModel* parent);
	virtual ~LV_ProxyModel();


public:

};


#endif // !LV_PROXYMODEL_H

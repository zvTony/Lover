#ifndef LV_ITEM_H
#define LV_ITEM_H

#include "../../../include/header.h"

class LV_Item : public QObject
{
	Q_OBJECT
public:
	LV_Item(QObject* parent = nullptr);
	virtual ~LV_Item();

	virtual int      rowCount();
	virtual LV_Item* child(int index);
	virtual void     addChild(LV_Item* item)    { if (m_pChild) m_pChild->append(item); }
	virtual QString  get_name(int index = 0)    { return QString(); }
	virtual QIcon    get_icon(int column = 0)   { return QIcon(); }
	virtual QString  get_title()                { return QString(); }
	/*load current data*/
	virtual bool     loadChild(const QString& viewName)    { return false; }
	/*load child data*/
	virtual bool     loadChild()                           { return false; }

	/*
	*@param type : event type, like CLICK,DOUBLECLIC,
	*@param index: context menu index,action point
	*/
	virtual bool     execute(enumEvent_Type type,int index = 0){ return false; }

	virtual Qt::ItemFlags flags() const          { return Qt::ItemIsSelectable | Qt::ItemIsEnabled; }

private:
	QList<LV_Item*>*    m_pChild;

};

#endif // !LV_ITEM_H

#ifndef LV_BASEVIEW_H
#define LV_BASEVIEW_H

#include "../../../include/header.h"

class LV_BaseView : public QWidget
{
public:
	LV_BaseView(QWidget* parent = nullptr);
	virtual ~LV_BaseView();

	enum enumViewType
	{
		TREE_VIEW,
		TABLE_VIEW,
		SEARCH_VIEW
	};

	bool createView(enumViewType type, QAbstractItemModel* model);
	void setHeaderHide(bool header)     { m_headerHide = header; }

public slots:
    void onDoubleClick(const QModelIndex &index);
    void onClick(const QModelIndex &index);
    void onContenxtMenu(const QModelIndex &index);

private:
	LV_Item* getItem(const QModelIndex& index);

private:
	QAbstractItemView* m_pView;
	QVBoxLayout*       m_pVLayout;
	bool               m_headerHide;
};

#endif // !LV_BASEVIEW_H

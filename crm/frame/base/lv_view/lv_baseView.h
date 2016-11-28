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

public:
	QAbstractItemView* m_pView;
	bool               m_headerHide;
};

#endif // !LV_BASEVIEW_H
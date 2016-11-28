#include "lv_baseView.h"
#include "../lv_model/lv_proxyModel.h"

LV_BaseView::LV_BaseView(QWidget* parent)
	: QWidget(parent)
{
	m_pView = nullptr;
	m_headerHide = true;
}

LV_BaseView::~LV_BaseView()
{
	if (m_pView)
		delete m_pView;
}

bool LV_BaseView::createView(enumViewType type, QAbstractItemModel* model)
{
	if (type = TABLE_VIEW)
	{
		m_pView = new QTreeView(this);
		static_cast<QTreeView*>(m_pView)->setModel(model);
		static_cast<QTreeView*>(m_pView)->setHeaderHidden(m_headerHide);
	}
	else if (type == TREE_VIEW)
	{
		m_pView = new QTableView(this);
		m_pView->setModel(model);
	}

	return true;
}
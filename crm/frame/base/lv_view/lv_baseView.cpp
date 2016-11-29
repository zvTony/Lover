#include "lv_baseView.h"
#include "../lv_model/lv_proxyModel.h"

LV_BaseView::LV_BaseView(QWidget* parent)
	: QWidget(parent)
{
	m_pView = nullptr;
	m_pVLayout = nullptr;
	m_headerHide = true;
}

LV_BaseView::~LV_BaseView()
{
	PTR_DEL(m_pVLayout);
	PTR_DEL(m_pView);
}

bool LV_BaseView::createView(enumViewType type, QAbstractItemModel* model)
{
	auto proxy = new LV_ProxyModel();
	proxy->setSourceModel(model);

	m_pVLayout = new QVBoxLayout(this);
	if (type = TABLE_VIEW)
	{
		m_pView = new QTreeView(this);
		static_cast<QTreeView*>(m_pView)->setModel(proxy);
		static_cast<QTreeView*>(m_pView)->setHeaderHidden(m_headerHide);
	}
	else if (type == TREE_VIEW)
	{
		m_pView = new QTableView(this);
		m_pView->setModel(proxy);
	}
	m_pVLayout->addWidget(m_pView);
	m_pVLayout->setContentsMargins(0, 0, 0, 0);

	return true;
}
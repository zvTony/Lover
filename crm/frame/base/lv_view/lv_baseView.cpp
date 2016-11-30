#include "lv_baseView.h"
#include "../lv_model/lv_proxyModel.h"
#include "../lv_item/lv_item.h"

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

void LV_BaseView::onDoubleClick(const QModelIndex &index)
{
	auto item = getItem(index);
	if (item == nullptr)
		return;
	item->execute(DOUBLECLICK);
}
void LV_BaseView::onClick(const QModelIndex &index)
{

}
void LV_BaseView::onContenxtMenu(const QModelIndex &index)
{

}

LV_Item* LV_BaseView::getItem(const QModelIndex& index)
{
	if (!index.isValid())
		return nullptr;
	
	
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
		static_cast<QTreeView*>(m_pView)->setContextMenuPolicy(Qt::CustomContextMenu);
	}
	else if (type == TREE_VIEW)
	{
		m_pView = new QTableView(this);
		m_pView->setModel(proxy);
	}
	m_pVLayout->addWidget(m_pView);
	m_pVLayout->setContentsMargins(0, 0, 0, 0);

	connect(m_pView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onDoubleClick(const QModelIndex&)));


	return true;
}
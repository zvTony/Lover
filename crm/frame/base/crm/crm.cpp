#include <QCloseEvent>
#include <QSettings>
#include <QMessageBox>
#include <QFile>
#include "crm.h"
#include "ui_crm.h"
#include "../lv_uimanage.h"

#include "../../../include/header.h"
#include "../lv_item/lvitem_customer/lvitem_customer.h"

const QString CRM_SETTINGS = "./settings.ini";
LV_UIManage* g_pUIManage = nullptr;

crm::crm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::crm)
{
	init();
}

void crm::init()
{
	ui->setupUi(this);
	showMaximized();
	readSettings();
	m_clearFlag = false;

	createMenu();

	g_pUIManage = new LV_UIManage(this, ui->menuBar, ui->statusBar);

	g_pUIManage->addDBPath("../../bin/crm.db");

	auto item = new LvItem_Customer();
	item->loadChild("");
	g_pUIManage->addLeftTree(item);
}

crm::~crm()
{
    delete ui;
}

void crm::readSettings()
{
	QSettings settings(CRM_SETTINGS, QSettings::IniFormat);
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
}

void crm::writeSettings()
{
	QSettings settings(CRM_SETTINGS, QSettings::IniFormat);
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
}

void crm::clearSettings()
{
	QFile settings(CRM_SETTINGS);
	settings.remove();

	m_clearFlag = true;
}

void crm::closeEvent(QCloseEvent *event)
{
	if (!m_clearFlag)
		writeSettings();
    QMainWindow::closeEvent(event);
}

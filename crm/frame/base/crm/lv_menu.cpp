#include <QMenuBar>
#include "ui_crm.h"
#include "crm.h"
#include "lv_menu.h"

void crm::createMenu()
{
	auto menuBar = ui->menuBar;
	auto menu = new Menu();
	auto fileMenu = menuBar->addMenu(QStringLiteral("&�ļ�"));
	QAction* exitAction = new QAction(QIcon(), QStringLiteral("�˳�"));
	fileMenu->addAction(exitAction);

	connect(exitAction, SIGNAL(triggered(bool)), menu, SLOT(onExit(bool)));
}

Menu::Menu(QObject* parent) : QObject(parent)
{

}

Menu::~Menu()
{

}

void Menu::onExit(bool)
{
	exit(0);
}
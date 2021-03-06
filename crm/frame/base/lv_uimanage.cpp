#include <QMainWindow>
#include <QApplication>
#include <QMenuBar>
#include <QStatusBar>
#include <QDir>
#include <QFile>
#include <QDockWidget>
#include <QTextBrowser>
#include <QDateTime>
#include <QDebug>
#include "lv_uimanage.h"
#include "lv_model/lv_model.h"
#include "lv_item/lv_item.h"

const QString LOGFILENAME = "log.txt";
const int     MAXLOGCOUNT = 1000;

LV_DB* g_pDB = nullptr;

QDockWidget* LV_UIManage::m_pDockFirst = nullptr;
LV_UIManage::LV_UIManage(QMainWindow* window, QMenuBar* menuBar, QStatusBar* statusBar)
	:QWidget(nullptr), m_pMainWin(window), m_pMenuBar(menuBar), m_pStatusBar(statusBar)
{
	init();
}

LV_UIManage::~LV_UIManage()
{
	PTR_DEL(m_pTabWidget);    // center tab widget
	PTR_DEL(m_pLogView);      // log view
	PTR_DEL(m_pMenuBar);
	PTR_DEL(m_pStatusBar);
	PTR_DEL(m_pMainWin);
}

void LV_UIManage::init()
{
	// log view
	m_pLogView = new QTextBrowser(this);
	addDockView(BOTTOM, m_pLogView, "Log View");
	connect(this, SIGNAL(log(enumLogLevel, const QString&)), this, SLOT(Log(enumLogLevel, const QString&)));

	// center view
	m_pTabWidget = new QTabWidget(this);
	m_pMainWin->setCentralWidget(m_pTabWidget);
}

void LV_UIManage::showStatus(const QString& text)
{
	if (m_pStatusBar)
	{
		m_pStatusBar->showMessage(text);
	}
}

QString LV_UIManage::getInstancePath()
{
	auto binPath = QApplication::applicationDirPath();
	return binPath;
}

bool LV_UIManage::addLeftTree(LV_Item* item)
{
	if (item == nullptr)
		return false;

	auto model = new LV_Model(item);

	auto view = new LV_BaseView();
	view->createView(LV_BaseView::TREE_VIEW, model);

	addDockView(LEFT, view, item->get_title(), QIcon());
	return true;
}

bool LV_UIManage::addDBPath(const QString& dbPath, const QString& sqlFilePath)
{
	g_pDB = new LV_DB();
#ifdef NDEBUG    // release
	g_pDB->open(":memory:");
#else
	g_pDB->open(dbPath);
#endif

	if (!sqlFilePath.isEmpty())
		g_pDB->exec(sqlFilePath);
	return true;
}

bool LV_UIManage::addDockView(enumDockPos pos, QWidget* widget, const QString& title, const QIcon& icon)
{
	if (CENTER == pos)
	{

	}
	else
	{
		QDockWidget* dockWidget = new QDockWidget();
		dockWidget->setWidget(widget);
		dockWidget->setWindowTitle(title);
		dockWidget->setWindowIcon(icon);
		if (LEFT == pos)
		{
			if (!m_pDockFirst)
			{
				m_pMainWin->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
				m_pDockFirst = dockWidget;
			}
			else
			{
				m_pMainWin->tabifyDockWidget(m_pDockFirst, dockWidget);
			}
			
		}
		else if (RIGHT == pos)
		{
			m_pMainWin->addDockWidget(Qt::RightDockWidgetArea, dockWidget);
		}
		else if (BOTTOM == pos)
		{
			m_pMainWin->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
		}
		else
		{
			return false;
		}
	}
	return true;
}

void LV_UIManage::Log(enumLogLevel level, const QString& describe)
{
	QString LevelArray[] = { "DEBUG", "WARING", "ERROR" };

	QDateTime UTC(QDateTime::currentDateTimeUtc());
	QDateTime local(UTC.toLocalTime());

	auto strLog = QString("[%1][%2]:%3\r\n")
		.arg(LevelArray[level])
		.arg(local.toString())
		.arg(describe);

	if (m_pLogView)
	{
		if (m_pLogView->document()->blockCount() > MAXLOGCOUNT)
			m_pLogView->document()->clear();
		m_pLogView->append(strLog);
	}
	auto logFilePath = QString("%1/%2").arg(getInstancePath()).arg(LOGFILENAME);
	QFile logFile(logFilePath);
	if (logFile.open(QIODevice::WriteOnly | QIODevice::Append))
	{
		logFile.write(strLog.toStdString().c_str());
	}
}
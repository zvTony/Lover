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
#include "uimanage.h"

const QString LOGFILENAME = "log.txt";
const int     MAXLOGCOUNT = 1000;

UIManage::UIManage(QMainWindow* window, QMenuBar* menuBar, QStatusBar* statusBar)
	:QWidget(nullptr), m_pMainWin(window), m_pMenuBar(menuBar), m_pStatusBar(statusBar)
{
	init();
}

UIManage::~UIManage()
{
	PTR_DEL(m_pLogView);
	PTR_DEL(m_pMenuBar);
	PTR_DEL(m_pStatusBar);
	PTR_DEL(m_pMainWin);
}

void UIManage::init()
{
	// log view
	m_pLogView = new QTextBrowser(this);
	addDockView(BOTTOM, m_pLogView, "Log View");

	connect(this, SIGNAL(log(enumLogLevel, const QString&)), this, SLOT(Log(enumLogLevel, const QString&)));
}

void UIManage::showStatus(const QString& text)
{
	if (m_pStatusBar)
	{
		m_pStatusBar->showMessage(text);
	}
}

QString UIManage::getInstancePath()
{
	auto binPath = QApplication::applicationDirPath();
	return binPath;
}

bool UIManage::addDockView(enumDockPos pos, QWidget* widget, const QString& title, const QIcon& icon)
{
	if (LEFT == pos)
	{

	}
	else if (RIGHT == pos)
	{

	}
	else if (BOTTOM == pos)
	{
		QDockWidget* dockWidget = new QDockWidget();
		dockWidget->setWidget(widget);
		dockWidget->setWindowTitle(title);
		dockWidget->setWindowIcon(icon);
		m_pMainWin->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
	}
	else if (CENTER == pos)
	{

	}
	else
	{
		return false;
	}
	return true;
}

void UIManage::Log(enumLogLevel level, const QString& describe)
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
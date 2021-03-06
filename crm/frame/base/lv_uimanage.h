#ifndef LV_UIMANAGE_H
#define LV_UIMANAGE_H

#include "../../include/header.h"

class QMenuBar;
class QStatusBar;
class QMainWindow;
class QTextBrowser;
class QDockWidget;
class LV_UIManage : public QWidget
{
	Q_OBJECT
public:
	LV_UIManage(QMainWindow* window, QMenuBar* menuBar, QStatusBar* statusBar);
	virtual ~LV_UIManage();

	enum enumDockPos{ LEFT, RIGHT, BOTTOM, CENTER};
	enum enumLogLevel{ DEBUG = 0, WARING, ERROR };

public:
	void       showStatus(const QString& text);

public:
	bool       addLeftTree(LV_Item* item);
	bool       addDBPath(const QString& dbPath, const QString& sqlFilePath = QString());

public:
	QString    getInstancePath();

public slots:
	void       Log(enumLogLevel level, const QString& describe);

signals:
	void       log(enumLogLevel level, const QString& describe);

private:
	void       init();
	bool       addDockView(enumDockPos pos, QWidget* widget, const QString& title, const QIcon& icon = QIcon());

private:
	QMainWindow*    m_pMainWin;
	QMenuBar*       m_pMenuBar;
	QStatusBar*     m_pStatusBar;

	QTextBrowser*   m_pLogView;
	QTabWidget*     m_pTabWidget;

	static QDockWidget* m_pDockFirst;
};
#endif // !LV_UIMANAGE_H

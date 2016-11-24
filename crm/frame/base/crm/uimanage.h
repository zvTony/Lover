#ifndef UIMANAGE_H
#define UIMANAGE_H

#include <QWidget>
#include <QIcon>

#define PTR_DEL(T) do { if (T){ delete T; T = nullptr; } break; } while (1);

class QMenuBar;
class QStatusBar;
class QMainWindow;
class QTextBrowser;
class UIManage : public QWidget
{
	Q_OBJECT
public:
	UIManage(QMainWindow* window, QMenuBar* menuBar, QStatusBar* statusBar);
	virtual ~UIManage();

	enum enumDockPos{ LEFT, RIGHT, BOTTOM, CENTER};
	enum enumLogLevel{ DEBUG = 0, WARING, ERROR };

public:
	void       showStatus(const QString& text);

public:
	bool       addDockView(enumDockPos pos, QWidget* widget, const QString& title, const QIcon& icon = QIcon());

public:
	QString    getInstancePath();

public slots:
	void       Log(enumLogLevel level, const QString& describe);

signals:
	void       log(enumLogLevel level, const QString& describe);

private:
	void       init();

private:
	QMainWindow*    m_pMainWin;
	QMenuBar*       m_pMenuBar;
	QStatusBar*     m_pStatusBar;

	QTextBrowser*   m_pLogView;
};
#endif // !UIMANAGE_H

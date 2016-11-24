#ifndef CRM_H
#define CRM_H

#include <QMainWindow>

namespace Ui {
class crm;
}

class crm : public QMainWindow
{
    Q_OBJECT

public:
    explicit crm(QWidget *parent = nullptr);
    virtual ~crm();

private:
	void init();
	void createMenu();

private:
    void readSettings();
    void writeSettings();
    void clearSettings();
    void closeEvent(QCloseEvent *event);

private:
    Ui::crm*    ui;
	bool        m_clearFlag;
};

#endif // CRM_H

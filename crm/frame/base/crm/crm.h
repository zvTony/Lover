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
    explicit crm(QWidget *parent = 0);
    ~crm();

private:
    Ui::crm *ui;
};

#endif // CRM_H

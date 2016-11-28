#ifndef HEADER_H
#define HEADER_H

#include <QObject>
#include <QWidget>
#include <QIcon>
#include <QList>
#include <QMap>
#include <QPair>
#include <QMessageBox>
#include <QTreeView>
#include <QTableView>
#include <QAbstractItemView> 
#include <QHBoxLayout>
#include <QVBoxLayout>

class LV_Item;
class LV_Model;
class LV_ProxyModel;
class LV_BaseView;

#define PTR_DEL(T) do { if (T){ delete T; T = nullptr; } break; } while (1);

#include "../frame/base/lv_view/lv_baseView.h"


#endif // !HEADER_H

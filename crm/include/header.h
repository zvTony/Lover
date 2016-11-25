#ifndef HEADER_H
#define HEADER_H

#include <QObject>
#include <QWidget>
#include <QIcon>
#include <QList>
#include <QMap>
#include <QPair>
#include <QMessageBox>

class LV_Item;

#define PTR_DEL(T) do { if (T){ delete T; T = nullptr; } break; } while (1);


#endif // !HEADER_H

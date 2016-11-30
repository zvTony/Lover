#ifndef LV_DB_H
#define LV_DB_H

#include "../../../third/sqlite3/sqlite3.h"
#include "../../../include/header.h"

int callBack(void*, int, char**, char**);

class LV_DB : public QObject
{
	Q_OBJECT
public:
	LV_DB();
	virtual ~LV_DB();

public:
	bool open(const QString& dbFileName);

	QStringList queryArray(const QString& sql);
	bool exec(const QString& sql);
	QString lastError();

private:
	sqlite3*    m_pDB;
};

#endif // !LV_DB_H

#include <QStringList>
#include "lv_db.h"

LV_DB::LV_DB()
{
	sqlite3_enable_shared_cache(0);
	m_pDB = nullptr;
}

LV_DB::~LV_DB()
{
	if (m_pDB)
	{
		sqlite3_close(m_pDB);
		m_pDB = nullptr;
	}
}

bool LV_DB::open(const QString& dbFileName)
{
	sqlite3* db = nullptr;
	int result = -1;
	int openMode = (SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE | SQLITE_OPEN_URI | SQLITE_OPEN_FULLMUTEX);
	if (sqlite3_open_v2(dbFileName.toUtf8().constData(), &db, openMode, nullptr) == SQLITE_OK)
	{
		m_pDB = db;
		sqlite3_enable_load_extension(db, 1);
	}
	else
	{
		if (db != nullptr)
			sqlite3_close(db);
		return false;
	}
	sqlite3_busy_timeout(db, 600000);
	return true;
}

QStringList LV_DB::queryArray(const QString& sql)
{
	QStringList ret;
	sqlite3_exec(m_pDB, sql.toUtf8(), callBack, &ret, nullptr);
	return ret;
}
bool LV_DB::exec(const QString& sql)
{
	auto result = sqlite3_exec(m_pDB, sql.toUtf8(), nullptr, nullptr, nullptr);
	if (result != SQLITE_OK)
		return false;
	return true;
}

QString LV_DB::lastError()
{
	if (m_pDB == nullptr)
		return QString();
	auto err = sqlite3_errmsg(m_pDB);
	return err;
}

int callBack(void* argc, int count, char** value, char**)
{
	for (int i = 0; i < count; ++i)
	{
		auto field = *value;
		static_cast<QStringList*>(argc)->push_back(field);
	}
	return 0;
}
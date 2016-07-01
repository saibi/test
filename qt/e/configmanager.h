#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QObject>

class ConfigManager : public QObject
{
	Q_OBJECT

public:
	explicit ConfigManager(QObject * parent = 0);
	~ConfigManager();

	Q_DISABLE_COPY(ConfigManager)

public:
	static ConfigManager & instance()
	{
		static ConfigManager manager;
		return manager;
	}

	bool reopen();
	bool setData();
	bool close();

};

#endif // CONFIGMANAGER_H

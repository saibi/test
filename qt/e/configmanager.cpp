#include "configmanager.h"

#include <QDateTime>

ConfigManager::ConfigManager(QObject *parent) : QObject(parent)
{
	qsrand( QDateTime::currentDateTime().toMSecsSinceEpoch() );

}

ConfigManager::~ConfigManager()
{
}

bool ConfigManager::reopen()
{
	qDebug("[ConfigManager::reopen]");

	return true;
}

bool ConfigManager::setData()
{
	qDebug("[ConfigManager::setData]");

	int number = qrand() % 100;

	if ( number & 0x01 )
	{
		qDebug("[ConfigManager::setData] true");
		return true;
	}
	else
	{
		qDebug("[ConfigManager::setData] false");
		throw number;
	}
	return false;
}

bool ConfigManager::close()
{
	qDebug("[ConfigManager::close]");
	return true;
}

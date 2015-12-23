#ifndef BUTTONCONTROLLER_H
#define BUTTONCONTROLLER_H

#include <QObject>
#include <QLocalSocket>
#include <QProcess>

class ButtonController : public QObject
{
	Q_OBJECT
public:
	explicit ButtonController(QObject *parent = 0);
	~ButtonController();

	static ButtonController & instance()
	{
		static ButtonController control;
		return control;
	}

	void connectToServer(const QString & name = "");
	void disconnectFromServer();
	void sendCommand(const QString & cmd);
	bool launchServer(const QString & serverPath);
	bool isConnected() { return m_connected; }
	//bool terminateServer();

signals:

private slots:
	void slotSocketError(QLocalSocket::LocalSocketError socketError);
	void slotConnected();

private:
	QLocalSocket * m_socket;

	bool m_connected;

	//QProcess m_serverProcess;

	int m_error;
};

#endif // CONTROLLER_H

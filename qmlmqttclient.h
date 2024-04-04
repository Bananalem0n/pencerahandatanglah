#ifndef QMLMQTTCLIENT_H
#define QMLMQTTCLIENT_H

#include <QtCore/QMap>
#include <QtMqtt/QMqttClient>
#include <QtQml/qqml.h>

class QmlMqttClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString hostname READ hostname WRITE setHostname NOTIFY hostnameChanged)
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(QMqttClient::ClientState state READ state WRITE setState NOTIFY stateChanged)
    QML_NAMED_ELEMENT(MqttClient)
    QML_EXTENDED_NAMESPACE(QMqttClient)


public:
    QmlMqttClient(QObject *parent = nullptr);

    Q_INVOKABLE void connectToHost();
    Q_INVOKABLE void disconnectFromHost();
    Q_INVOKABLE qint32 publish(const QString &topic, const QString &message, int qos=0, bool retain=false);

    // hostname
    const QString hostname() const;
    void setHostname(const QString &hostname);

    // username
    const QString username() const;
    void setUsername(const QString &username);

    // password
    const QString password() const;
    void setPassword(const QString &password);

    // port
    int port() const;
    void setPort(int port);

    // state
    const QMqttClient::ClientState state() const;
    void setState(const QMqttClient::ClientState &state);

signals:
    void hostnameChanged(QString hostname);
    void usernameChanged(QString username);
    void passwordChanged(QString password);
    void portChanged(quint16 port);
    void stateChanged(QMqttClient::ClientState state);

private:
    Q_DISABLE_COPY(QmlMqttClient)
    QMqttClient m_client;
};

#endif // QMLMQTTCLIENT_H

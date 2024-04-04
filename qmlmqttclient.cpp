#include "qmlmqttclient.h"
#include <QDebug>
#include <QMqttTopicName>

QmlMqttClient::QmlMqttClient(QObject *parent)
    : QObject(parent)
{
    connect(&m_client, &QMqttClient::hostnameChanged, this, &QmlMqttClient::hostnameChanged);
    connect(&m_client, &QMqttClient::portChanged, this, &QmlMqttClient::portChanged);
    connect(&m_client, &QMqttClient::stateChanged, this, &QmlMqttClient::stateChanged);
    connect(&m_client, &QMqttClient::usernameChanged, this, &QmlMqttClient::usernameChanged);
    connect(&m_client, &QMqttClient::passwordChanged, this, &QmlMqttClient::passwordChanged);
}


void QmlMqttClient::connectToHost(){
    m_client.connectToHost();
}

void QmlMqttClient::disconnectFromHost() {
    m_client.disconnectFromHost();
}

const QString QmlMqttClient::hostname() const {
    return m_client.hostname();
}

void QmlMqttClient::setHostname(const QString &hostname) {
    m_client.setHostname(hostname);
}

const QString QmlMqttClient::username() const {
    return m_client.username();
}

void QmlMqttClient::setUsername(const QString &username) {
    m_client.setUsername(username);
}

const QString QmlMqttClient::password() const {
    return m_client.password();
}

void QmlMqttClient::setPassword(const QString &password) {
    m_client.setPassword(password);
}

int QmlMqttClient::port() const
{
    return m_client.port();
}

void QmlMqttClient::setPort(int newPort)
{
    if (newPort < 0 || newPort > std::numeric_limits<quint16>::max()) {
        qWarning() << "Trying to set invalid port number";
        return;
    }
    m_client.setPort(newPort);
}


void QmlMqttClient::setState(const QMqttClient::ClientState &state)
{
    m_client.setState(state);
}

const QMqttClient::ClientState QmlMqttClient::state() const {
    return m_client.state();
}

qint32 QmlMqttClient::publish(const QString &topic, const QString &message, int qos, bool retain)
{
    auto result = m_client.publish(QMqttTopicName(topic), message.toUtf8(), qos, retain);
    return result;
}





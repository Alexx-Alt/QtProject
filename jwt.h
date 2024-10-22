#ifndef JWT_H
#define JWT_H

#include <QString>
#include <QJsonObject>

class JWT
{
public:
    static QString encode(const QJsonObject &payload, const QString &secret);
    static bool decode(const QString &token, QJsonObject &payload, const QString &secret);
    static QString base64UrlEncode(const QByteArray &input);
    static QByteArray base64UrlDecode(const QString &input);
    static bool verify(const QString &token, const QString &secret);
};

#endif // JWT_H

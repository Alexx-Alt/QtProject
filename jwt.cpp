#include "jwt.h"
#include <QJsonDocument>
#include <QCryptographicHash>
#include <QMessageAuthenticationCode>

QString JWT::encode(const QJsonObject &payload, const QString &secret)
{
    QJsonObject header;
    header["alg"] = "HS256";
    header["typ"] = "JWT";

    QByteArray headerBA = QJsonDocument(header).toJson(QJsonDocument::Compact);
    QByteArray payloadBA = QJsonDocument(payload).toJson(QJsonDocument::Compact);

    QString headerEncoded = base64UrlEncode(headerBA);
    QString payloadEncoded = base64UrlEncode(payloadBA);

    QString dataToSign = headerEncoded + "." + payloadEncoded;
    QByteArray signature = QMessageAuthenticationCode::hash(dataToSign.toUtf8(), secret.toUtf8(), QCryptographicHash::Sha256);

    return dataToSign + "." + base64UrlEncode(signature);
}

bool JWT::decode(const QString &token, QJsonObject &payload, const QString &secret)
{
    QStringList parts = token.split(".");
    if (parts.size() != 3) return false;

    QString headerEncoded = parts[0];
    QString payloadEncoded = parts[1];
    QString signatureEncoded = parts[2];

    QByteArray headerBA = base64UrlDecode(headerEncoded);
    QByteArray payloadBA = base64UrlDecode(payloadEncoded);
    QByteArray signatureBA = base64UrlDecode(signatureEncoded);

    QJsonDocument payloadDoc = QJsonDocument::fromJson(payloadBA);
    payload = payloadDoc.object();

    QString dataToSign = headerEncoded + "." + payloadEncoded;
    QByteArray expectedSignature = QMessageAuthenticationCode::hash(dataToSign.toUtf8(), secret.toUtf8(), QCryptographicHash::Sha256);

    return (signatureBA == expectedSignature);
}

QString JWT::base64UrlEncode(const QByteArray &input)
{
    QString base64 = input.toBase64();
    base64.replace("+", "-");
    base64.replace("/", "_");
    base64.replace("=", "");
    return base64;
}

QByteArray JWT::base64UrlDecode(const QString &input)
{
    QString base64 = input;
    base64.replace("-", "+");
    base64.replace("_", "/");
    switch (base64.length() % 4) {
    case 2: base64.append("=="); break;
    case 3: base64.append("="); break;
    }
    return QByteArray::fromBase64(base64.toUtf8());
}

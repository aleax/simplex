#ifndef TFPARSER_H
#define TFPARSER_H

#include <QString>
#include <QVector>
#include <QRegExp>
#include <QDebug>

class TFParser
{
    QVector<qreal> C;
    bool error;
    QString parsed;
public:
    TFParser();
    void parse(QString input);
    bool isError(){return error;}
    QVector<qreal> getC(){return C;}
    QString getFunction(){return parsed;}
};

#endif // TFPARSER_H

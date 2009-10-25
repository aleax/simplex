#ifndef TFPARSER_H
#define TFPARSER_H

#include <QString>
#include <QVector>
#include <QRegExp>

class TFParser
{
    QVector<double> C;
    bool error;
    QString parsed;
public:
    TFParser(QString input);
};

#endif // TFPARSER_H

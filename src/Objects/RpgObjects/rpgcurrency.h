#ifndef TABLETOPLIB_RPGCURRENCY_H
#define TABLETOPLIB_RPGCURRENCY_H

#include <tabletopobject.h>
#include "TableTopLib_global.h"

namespace TableTopLib {

class TABLETOPLIB_EXPORT RpgCurrency : public TableTopLib::TableTopObject
{
    Q_OBJECT
public:
    explicit RpgCurrency(QObject *parent = nullptr);
    struct Currency{
        QString currencyType;
        int currencyAmount;
    };
protected:
    QList<Currency> m_currencies;
};

} // namespace TableTopLib

#endif // TABLETOPLIB_RPGCURRENCY_H

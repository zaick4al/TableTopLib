#ifndef TABLETOPLIB_RPGCURRENCY_H
#define TABLETOPLIB_RPGCURRENCY_H

#include <tabletopobject.h>
#include "TableTopLib_global.h"

namespace TableTopLib {
/**
 * @brief The RpgCurrency class
 * The custom library's currency type for player's inventory
 */
class TABLETOPLIB_EXPORT RpgCurrency : public TableTopLib::TableTopObject
{
    Q_OBJECT
public:
    /**
     * @brief RpgCurrency
     * Constructor
     * @param p_id - long long this currency's id
     * @param parent
     */
    explicit RpgCurrency(long long p_id, QObject *parent = nullptr);
    /**
     * @brief The Currency struct
     * @variable currencyType - QString - type of this currency
     * @variable currencyAmount - int - amount of this currency in inventory
     */
    struct Currency{
        QString currencyType;
        int currencyAmount;
    };
protected:
    /**
     * @brief m_currencies
     * All currencies that some player possesses
     */
    QList<Currency> m_currencies;
};
typedef std::shared_ptr<RpgCurrency> RpgCurrency_ptr;
} // namespace TableTopLib

#endif // TABLETOPLIB_RPGCURRENCY_H

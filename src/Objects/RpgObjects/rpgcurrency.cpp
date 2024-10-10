#include "rpgcurrency.h"

namespace TableTopLib {

RpgCurrency::RpgCurrency(long long p_id, QObject *parent)
    : TableTopLib::TableTopObject{parent}
{
    setId(p_id);
}

} // namespace TableTopLib

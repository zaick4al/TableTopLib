#include "die.h"

namespace TableTopLib {

Die::Die(long long p_id, QObject *parent)
    : TableTopLib::TableTopObject{parent},
    m_dieSides(6)
{
    setId(p_id);
}

QList<int> Die::rollTheDice(int p_diceAmount)
{
    QList<int> t_results;
    for(int i = 0; i < p_diceAmount; i++)
    {
        t_results << QRandomGenerator::global()->bounded(1, dieSides());
    }
    return t_results;
}

int Die::dieSides() const
{
    return m_dieSides;
}

void Die::setDieSides(int p_dieSides)
{
    m_dieSides = p_dieSides;
}

} // namespace TableTopLib

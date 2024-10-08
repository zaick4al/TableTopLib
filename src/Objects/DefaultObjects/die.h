#ifndef TABLETOPLIB_DIE_H
#define TABLETOPLIB_DIE_H

#include <tabletopobject.h>
#include <QRandomGenerator>

namespace TableTopLib {

class TABLETOPLIB_EXPORT Die : public TableTopLib::TableTopObject
{
    Q_OBJECT
public:
    explicit Die(long long p_id, QObject *parent = nullptr);

    virtual QList<int>rollTheDice(int p_diceAmount = 1);

    int dieSides() const;
    void setDieSides(int p_dieSides);

protected:
    int m_dieSides;
};
typedef std::shared_ptr<Die> Dice_ptr;

} // namespace TableTopLib

#endif // TABLETOPLIB_DIE_H

#ifndef TABLETOPLIB_DIE_H
#define TABLETOPLIB_DIE_H

#include <tabletopobject.h>
#include <QRandomGenerator>

namespace TableTopLib {

/**
 * @brief The Die class
 * The general class for dice to throw
 */
class TABLETOPLIB_EXPORT Die : public TableTopLib::TableTopObject
{
    Q_OBJECT
public:
    /**
     * @brief Die
     * Constructor
     * @param p_id - long long id of this object
     * @param parent
     */
    explicit Die(long long p_id, QObject *parent = nullptr);

    /**
     * @brief rollTheDice
     * Virtual method that rolls that dice
     * @param p_diceAmount - int amount of dices to roll
     * @return
     */
    virtual QList<int>rollTheDice(int p_diceAmount = 1);

    /**
     * @brief dieSides
     * @return int - current dice sides (d{int})
     */
    int dieSides() const;
    /**
     * @brief setDieSides
     * @param p_dieSides - int new value of dice sides (d{int})
     */
    void setDieSides(int p_dieSides);

protected:
    /**
     * @private
     */
    int m_dieSides;
};
typedef std::shared_ptr<Die> Dice_ptr;

} // namespace TableTopLib

#endif // TABLETOPLIB_DIE_H

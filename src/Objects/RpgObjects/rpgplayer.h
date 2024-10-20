#ifndef TABLETOPLIB_RPGPLAYER_H
#define TABLETOPLIB_RPGPLAYER_H

#include <player.h>
#include <RpgObjects/rpgcharacter.h>
#include "TableTopLib_global.h"

namespace TableTopLib {
/**
 * @brief The RpgPlayer class
 * This rpg player's class
 */
class TABLETOPLIB_EXPORT RpgPlayer : public TableTopLib::Player
{
    Q_OBJECT
    typedef std::shared_ptr<RpgPlayer> RpgPlayer_ptr;
public:
    /**
     * @brief RpgPlayer
     * Constructor
     * @param p_id - long long this player's id
     * @param parent
     */
    explicit RpgPlayer(long long p_id, QObject *parent = nullptr);

    /**
     * @brief playerCharacter
     * Getter of get this player's character
     * @return std::shared_ptr<RpgCharacter>
     */
    RpgCharacter_ptr playerCharacter() const;
    /**
     * @brief setPlayerCharacter
     * Setter of this player's character
     * @param p_playerCharacter - std::shared_ptr<RpgCharacter>
     */
    void setPlayerCharacter(const RpgCharacter_ptr &p_playerCharacter);

protected:
    /**
     * @private
     */
    RpgCharacter_ptr m_playerCharacter;
};
typedef std::shared_ptr<RpgPlayer> RpgPlayer_ptr;
} // namespace TableTopLib

#endif // TABLETOPLIB_RPGPLAYER_H

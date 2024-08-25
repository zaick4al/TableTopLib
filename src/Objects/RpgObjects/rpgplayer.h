#ifndef TABLETOPLIB_RPGPLAYER_H
#define TABLETOPLIB_RPGPLAYER_H

#include <player.h>
#include <RpgObjects/rpgcharacter.h>
#include "TableTopLib_global.h"

namespace TableTopLib {

class TABLETOPLIB_EXPORT RpgPlayer : public TableTopLib::Player
{
    Q_OBJECT
    typedef std::shared_ptr<RpgPlayer> RpgPlayer_ptr;
public:
    explicit RpgPlayer(QObject *parent = nullptr);

    RpgCharacter_ptr playerCharacter() const;
    void setPlayerCharacter(const RpgCharacter_ptr &p_playerCharacter);

    RpgPlayer_ptr thisPlayer();

protected:
    RpgCharacter_ptr m_playerCharacter;
};
typedef std::shared_ptr<RpgPlayer> RpgPlayer_ptr;
} // namespace TableTopLib

#endif // TABLETOPLIB_RPGPLAYER_H

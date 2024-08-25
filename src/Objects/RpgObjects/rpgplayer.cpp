#include "rpgplayer.h"

namespace TableTopLib {

RpgPlayer::RpgPlayer(QObject *parent)
    : TableTopLib::Player{parent}
{

}

RpgCharacter_ptr RpgPlayer::playerCharacter() const
{
    return m_playerCharacter;
}

void RpgPlayer::setPlayerCharacter(const RpgCharacter_ptr &p_playerCharacter)
{
    m_playerCharacter = p_playerCharacter;
}

RpgPlayer::RpgPlayer_ptr RpgPlayer::thisPlayer()
{
    return RpgPlayer_ptr(this);
}

} // namespace TableTopLib

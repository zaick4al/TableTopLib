#include "rpgplayer.h"

namespace TableTopLib {

RpgPlayer::RpgPlayer(long long p_id, QObject *parent)
    : TableTopLib::Player{p_id, parent}
{
    setId(p_id);
}

RpgCharacter_ptr RpgPlayer::playerCharacter() const
{
    return m_playerCharacter;
}

void RpgPlayer::setPlayerCharacter(const RpgCharacter_ptr &p_playerCharacter)
{
    m_playerCharacter = p_playerCharacter;
}

} // namespace TableTopLib

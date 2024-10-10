#include "dndplayer.h"

namespace TableTopLib {

DndPlayer::DndPlayer(long long p_id, QObject *parent)
    : TableTopLib::RpgPlayer{p_id, parent}
{
    setId(p_id);
}

TableTopLib::DndCharacter_ptr DndPlayer::playerCharacter() const
{
    return m_playerCharacter;
}

void DndPlayer::setPlayerCharacter(const TableTopLib::DndCharacter_ptr &p_playerCharacter)
{
    m_playerCharacter = p_playerCharacter;
}

DndPlayer::DndPlayer_ptr DndPlayer::thisPlayer()
{
    return DndPlayer_ptr(this);
}

} // namespace TableTopLib

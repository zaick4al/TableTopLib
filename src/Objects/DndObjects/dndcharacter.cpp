#include "dndcharacter.h"
#include <DndObjects/dndplayer.h>

namespace TableTopLib {

DndCharacter::DndCharacter(long long p_id, QObject *parent)
    : TableTopLib::RpgCharacter{p_id, parent}
{
    setId(p_id);
}

DndPlayer_ptr DndCharacter::characterPlayer() const
{
    return m_characterPlayer;
}

void DndCharacter::setCharacterPlayer(const DndPlayer_ptr &p_characterPlayer)
{
    m_characterPlayer = p_characterPlayer;
    if(m_characterPlayer->playerCharacter() != thisCharacter())
        m_characterPlayer->setPlayerCharacter(thisCharacter());
}

DndCharacter::DndCharacter_ptr DndCharacter::thisCharacter()
{
    return DndCharacter_ptr(this);
}

} // namespace TableTopLib

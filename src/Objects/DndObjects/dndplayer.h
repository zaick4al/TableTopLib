#ifndef TABLETOPLIB_DNDPLAYER_H
#define TABLETOPLIB_DNDPLAYER_H

#include <rpgplayer.h>
#include <DndObjects/dndcharacter.h>
#include "TableTopLib_global.h"

namespace TableTopLib {

class TABLETOPLIB_EXPORT DndPlayer : public TableTopLib::RpgPlayer
{
    Q_OBJECT
public:
    explicit DndPlayer(QObject *parent = nullptr);

    TableTopLib::DndCharacter_ptr playerCharacter() const;
    void setPlayerCharacter(const TableTopLib::DndCharacter_ptr &p_playerCharacter);

protected:
    TableTopLib::DndCharacter_ptr m_playerCharacter;
};

} // namespace TableTopLib

#endif // TABLETOPLIB_DNDPLAYER_H

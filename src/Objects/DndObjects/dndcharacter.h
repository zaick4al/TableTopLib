#ifndef TABLETOPLIB_DNDCHARACTER_H
#define TABLETOPLIB_DNDCHARACTER_H

#include "RpgObjects/rpgcharacter.h"
#include "TableTopLib_global.h"

namespace TableTopLib {
class DndPlayer;
typedef std::shared_ptr<DndPlayer> DndPlayer_ptr;

class TABLETOPLIB_EXPORT DndCharacter : public TableTopLib::RpgCharacter
{
    Q_OBJECT
    typedef std::shared_ptr<DndCharacter> DndCharacter_ptr;
public:
    explicit DndCharacter(long long p_id, QObject *parent = nullptr);

    DndPlayer_ptr characterPlayer() const;
    void setCharacterPlayer(const DndPlayer_ptr &p_characterPlayer);

    DndCharacter_ptr thisCharacter();
protected:
    DndPlayer_ptr m_characterPlayer;
};
typedef std::shared_ptr<DndCharacter> DndCharacter_ptr;
} // namespace TableTopLib

#endif // TABLETOPLIB_DNDCHARACTER_H

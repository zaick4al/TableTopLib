#ifndef TABLETOPLIB_DNDPLAYER_H
#define TABLETOPLIB_DNDPLAYER_H

#include <rpgplayer.h>
#include <DndObjects/dndcharacter.h>
#include "TableTopLib_global.h"

namespace TableTopLib {
/**
 * @brief The DndPlayer class
 * The custom class for d&d player
 */
class TABLETOPLIB_EXPORT DndPlayer : public TableTopLib::RpgPlayer
{
    Q_OBJECT
    typedef std::shared_ptr<DndPlayer> DndPlayer_ptr;
public:
    /**
     * @brief DndPlayer
     * Constructor of this class
     * @param p_id - long long id of this character
     * @param parent
     */
    explicit DndPlayer(long long p_id, QObject *parent = nullptr);

    /**
     * @brief playerCharacter
     * Getter of character of this player
     * @return std::shared_ptr<DndCharacter> - character of this player
     */
    TableTopLib::DndCharacter_ptr playerCharacter() const;
    /**
     * @brief setPlayerCharacter
     * Setter of this player's character
     * @param p_playerCharacter - std::shared_ptr<DndCharacter>
     */
    void setPlayerCharacter(const TableTopLib::DndCharacter_ptr &p_playerCharacter);

protected:
    /**
     * @private
     */
    TableTopLib::DndCharacter_ptr m_playerCharacter;
};
typedef std::shared_ptr<DndPlayer> DndPlayer_ptr;
} // namespace TableTopLib

#endif // TABLETOPLIB_DNDPLAYER_H

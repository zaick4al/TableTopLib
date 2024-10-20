#ifndef TABLETOPLIB_DNDCHARACTER_H
#define TABLETOPLIB_DNDCHARACTER_H

#include "RpgObjects/rpgcharacter.h"
#include "TableTopLib_global.h"

namespace TableTopLib {
class DndPlayer;
typedef std::shared_ptr<DndPlayer> DndPlayer_ptr;
/**
 * @brief The DndCharacter class
 * Class for D&D characters
 */
class TABLETOPLIB_EXPORT DndCharacter : public TableTopLib::RpgCharacter
{
    Q_OBJECT
    typedef std::shared_ptr<DndCharacter> DndCharacter_ptr;
public:
    /**
     * @brief DndCharacter
     * Constructor
     * @param p_id - this object's id
     * @param parent
     */
    explicit DndCharacter(long long p_id, QObject *parent = nullptr);

    /**
     * @brief characterPlayer
     * Getter of player who plays this character
     * @return std::shared_ptr<DndPlayer>
     */
    DndPlayer_ptr characterPlayer() const;
    /**
     * @brief setCharacterPlayer
     * Setter of player who plays this character
     * @param p_characterPlayer - std::shared_ptr<DndPlayer>
     */
    void setCharacterPlayer(const DndPlayer_ptr &p_characterPlayer);

protected:
    /**
     * @private
     */
    DndPlayer_ptr m_characterPlayer;
};
typedef std::shared_ptr<DndCharacter> DndCharacter_ptr;
} // namespace TableTopLib

#endif // TABLETOPLIB_DNDCHARACTER_H

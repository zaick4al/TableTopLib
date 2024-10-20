#ifndef TABLETOPLIB_RPGCHARACTER_H
#define TABLETOPLIB_RPGCHARACTER_H

#include <tabletopobject.h>
#include <QJsonObject>

namespace TableTopLib {

class RpgPlayer;
typedef std::shared_ptr<RpgPlayer> RpgPlayer_ptr;
/**
 * @brief The RpgCharacter class
 * Custom class of rpg character
 */
class TABLETOPLIB_EXPORT RpgCharacter : public TableTopLib::TableTopObject
{
    Q_OBJECT
    typedef std::shared_ptr<RpgCharacter> RpgCharacter_ptr;
public:
    /**
     * @brief The Skill struct
     * @variable skillName - QString - name of the skill
     * @variable skillStat - QString - description of that skill
     * @variable skillLevel - int - level of that skill
     */
    struct Skill{
        QString skillName;
        QString skillStat;
        int skillLevel = 0;
    };

    /**
     * @brief The Dice struct
     * @variable diceAmount - int - amount of dices
     * @variable diceSides - int - amount of sides in the dice
     */
    struct Dice{
        int diceAmount = 0;
        int diceSides = 0;
    };

    /**
     * @brief RpgCharacter
     * Constructor
     * @param p_id - long long id of this player
     * @param parent
     */
    explicit RpgCharacter(long long p_id, QObject *parent = nullptr);

    /**
     * @brief deserialize
     * Deserializer for this class from JSON
     * @param p_jsonObject - QJsonObject
     */
    virtual void deserialize(const QJsonObject &p_jsonObject);
    /**
     * @brief serialize
     * Serializer for this class to JSON
     * @return QJsonObject
     */
    virtual QJsonObject serialize();

    /**
     * @brief healthPoints
     * Getter for this character's current healthpoints
     * @return int
     */
    int healthPoints() const;
    /**
     * @brief setHealthPoints
     * Setter for current character's healthpoints
     * @param p_healthPoints - int
     */
    void setHealthPoints(int p_healthPoints);
    /**
     * @brief healCharacter
     * Quick method to heal this character
     * @param p_healedHealthPoints - int - Healthpoint to add
     */
    virtual void healCharacter(int p_healedHealthPoints);

    /**
     * @brief maxHealthPoints
     * Getter for this character's max healthpoints
     * @return int
     */
    int maxHealthPoints() const;
    /**
     * @brief setMaxHealthPoints
     * @param p_maxHealthPoints
     */
    void setMaxHealthPoints(int p_maxHealthPoints);
    /**
     * @brief increaseMaxHealthPoints
     * Quick method to increase this character's healthpoints
     * @param p_additionalMaxHealth - int - Value of healthpoints to increase max health
     */
    virtual void increaseMaxHealthPoints(int p_additionalMaxHealth);

    /**
     * @brief level
     * Getter of this character
     * @return int
     */
    int level() const;
    /**
     * @brief setLevel
     * Setter of this character's level
     * @param p_level - int - level of this character
     */
    void setLevel(int p_level);
    /**
     * @brief levelUp
     * Quick method to increase character's level by 1
     */
    virtual void levelUp();

    /**
     * @brief experiencePoints
     * Getter of this character's exp
     * @return int
     */
    int experiencePoints() const;
    /**
     * @brief setExperiencePoints
     * Setter of this character's exp
     * @param p_experiencePoints - int
     */
    void setExperiencePoints(int p_experiencePoints);
    /**
     * @brief addExperiencePoints
     * Quick method to increase character's experience points
     * @param p_additionalPoints - int - value to increase point by
     */
    virtual void addExperiencePoints(int p_additionalPoints);

    /**
     * @brief experiencePointsNeeded
     * Getter of how many points does it takes to level up
     * @return int
     */
    int experiencePointsNeeded() const;
    /**
     * @brief experiencePointsNeeded
     * Setter of how many points does it takes to level up
     * @param p_pointsNeeded - int - how many points does it take for this character to reach next level
     */
    void setExperiencePointsNeeded(int p_pointsNeeded);

    /**
     * @brief strength
     * Getter of this character's strenth stat
     * @return int
     */
    int strength();
    /**
     * @brief dexterity
     * Getter of this character's dexterity stat
     * @return int
     */
    int dexterity();
    /**
     * @brief constitution
     * Getter of this character's constitution stat
     * @return int
     */
    int constitution();
    /**
     * @brief intelligence
     * Getter of this character's intelligence stat
     * @return int
     */
    int intelligence();
    /**
     * @brief wisdom
     * Getter of this character's wisdom stat
     * @return int
     */
    int wisdom();
    /**
     * @brief charisma
     * Getter of this character's charisma stat
     * @return int
     */
    int charisma();

    /**
     * @brief hitDice
     * Getter of this character's levelup hitpoints increase dice
     * @return struct Dice
     */
    Dice hitDice() const;
    /**
     * @brief setHitDice
     * Setter of this character's levelup hitpoints increase dice
     * @param p_hitDice - struct Dice
     */
    void setHitDice(Dice p_hitDice);

    /**
     * @brief armorClass
     * Getter of this player's armor class
     * @return int
     */
    int armorClass() const;
    /**
     * @brief armorClass
     * Setter of this player's armor class
     * @param p_armorClass - int
     */
    void setArmorClass(int p_armorClass);

    /**
     * @brief stats
     * General QHash getter for all this character's stats combined
     * @return QHash<QString, int>
     */
    QHash<QString, int> stats() const;
    /**
     * @brief skills
     * General QHash getter of this character's skills
     * @return QHash<QString, struct Skill>
     */
    QHash<QString, Skill> skills() const;

    /**
     * @brief characterPlayer
     * Getter of this character's player
     * @return std::shared_ptr<RpgPlayer>
     */
    RpgPlayer_ptr characterPlayer() const;
    /**
     * @brief setCharacterPlayer
     * Setter of this character's player
     * @param p_characterPlayer - std::shared_ptr<RpgPlayer>
     */
    void setCharacterPlayer(const RpgPlayer_ptr &p_characterPlayer);

signals:
    /**
     * @brief healthPointsChanged
     * Signal to notify that this character's hitpoints have changed
     */
    void healthPointsChanged();
    /**
     * @brief levelChanged
     * Signal to notify that this character's level has changed
     */
    void levelChanged();

protected:
    /**
     * @private
     */
    int m_healthPoints;
    /**
     * @private
     */
    int m_maxHealthPoints;
    /**
     * @private
     */
    int m_level;
    /**
     * @private
     */
    int m_experiencePoints;
    /**
     * @private
     */
    int m_experiencePointsNeeded;
    /**
     * @private
     */
    Dice m_hitDice;
    /**
     * @private
     */
    int m_armorClass;
    /**
     * @private
     */
    QHash<QString, int> m_stats;
    /**
     * @private
     */
    QHash<QString, Skill> m_skills;
    /**
     * @private
     */
    RpgPlayer_ptr m_characterPlayer;
};

typedef std::shared_ptr<RpgCharacter> RpgCharacter_ptr;

} // namespace TableTopLib

#endif // TABLETOPLIB_RPGCHARACTER_H

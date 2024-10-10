#ifndef TABLETOPLIB_RPGCHARACTER_H
#define TABLETOPLIB_RPGCHARACTER_H

#include <tabletopobject.h>
#include <QJsonObject>

namespace TableTopLib {

class RpgPlayer;
typedef std::shared_ptr<RpgPlayer> RpgPlayer_ptr;

class TABLETOPLIB_EXPORT RpgCharacter : public TableTopLib::TableTopObject
{
    Q_OBJECT
    typedef std::shared_ptr<RpgCharacter> RpgCharacter_ptr;
public:
    struct Skill{
        QString skillName;
        QString skillStat;
        int skillLevel = 0;
    };

    struct Dice{
        int diceAmount = 0;
        int diceSides = 0;
    };

    explicit RpgCharacter(long long p_id, QObject *parent = nullptr);

    virtual void deserialize(const QJsonObject &p_jsonObject);
    virtual QJsonObject serialize();

    int healthPoints() const;
    void setHealthPoints(int p_healthPoints);
    virtual void healCharacter(int p_healedHealthPoints);

    int maxHealthPoints() const;
    void setMaxHealthPoints(int p_maxHealthPoints);
    virtual void increaseMaxHealthPoints(int p_additionalMaxHealth);

    int level() const;
    void setLevel(int p_level);
    virtual void levelUp();

    int experiencePoints() const;
    void setExperiencePoints(int p_experiencePoints);
    virtual void addExperiencePoints(int p_additionalPoints);

    int experiencePointsNeeded() const;
    void setExperiencePointsNeeded(int p_pointsNeeded);

    int strength();
    int dexterity();
    int constitution();
    int intelligence();
    int wisdom();
    int charisma();

    Dice hitDice() const;
    void setHitDice(Dice p_hitDice);

    int armorClass() const;
    void setArmorClass(int p_armorClass);

    QHash<QString, int> stats() const;
    QHash<QString, Skill> skills() const;

    RpgPlayer_ptr characterPlayer() const;
    void setCharacterPlayer(const RpgPlayer_ptr &p_characterPlayer);

    RpgCharacter_ptr thisCharacter();

signals:
    void healthPointsChanged();
    void levelChanged();

protected:
    int m_healthPoints;
    int m_maxHealthPoints;
    int m_level;
    int m_experiencePoints;
    int m_experiencePointsNeeded;
    Dice m_hitDice;
    int m_armorClass;
    QHash<QString, int> m_stats;
    QHash<QString, Skill> m_skills;
    RpgPlayer_ptr m_characterPlayer;
};

typedef std::shared_ptr<RpgCharacter> RpgCharacter_ptr;

} // namespace TableTopLib

#endif // TABLETOPLIB_RPGCHARACTER_H

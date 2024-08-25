#include "rpgcharacter.h"
#include <RpgObjects/rpgplayer.h>

namespace TableTopLib {

RpgCharacter::RpgCharacter(QObject *parent)
    : TableTopLib::TableTopObject{parent},
    m_level(0),
    m_experiencePoints(0),
    m_experiencePointsNeeded(0)
{}

void RpgCharacter::deserialize(const QJsonObject &p_jsonObject)
{
    if(p_jsonObject.value("type").toString() != "character")
        return;
    if(!p_jsonObject.contains("contents"))
        return;
    QJsonObject t_contents = p_jsonObject.value("contents").toObject();
    if(t_contents.contains("max_health_points"))
        setMaxHealthPoints(t_contents.value("max_health_points").toInt());
    if(t_contents.contains("health_points"))
        setHealthPoints(t_contents.value("health_points").toInt());
    if(t_contents.contains("character_level"))
        setLevel(t_contents.value("character_level").toInt());
    if(t_contents.contains("max_experience_points"))
        setExperiencePointsNeeded(t_contents.value("max_experience_points").toInt());
    if(t_contents.contains("experience_points"))
        setExperiencePoints(t_contents.value("experience_points").toInt());
    if(t_contents.contains("hit_dice"))
    {
        QJsonObject t_hitDice = t_contents.value("hit_dice").toObject();
        Dice t_newDice;
        t_newDice.diceAmount = t_hitDice.value("diceAmount").toInt();
        t_newDice.diceSides = t_hitDice.value("diceSides").toInt();
        setHitDice(t_newDice);
    }
    if(t_contents.contains("stats"))
    {
        QJsonObject t_stats = t_contents.value("stats").toObject();
        for(QString &key : t_stats.keys())
        {
            m_stats.insert(key, t_stats.value(key).toInt());
        }
    }
    if(t_contents.contains("skills"))
    {
        QJsonObject t_skills = t_contents.value("skills").toObject();
        for(const QString &key : t_skills.keys())
        {
            QJsonObject t_currentSkillJson = t_skills.value(key).toObject();
            Skill currentSkill;
            currentSkill.skillName = key;
            currentSkill.skillStat = t_currentSkillJson.value("skill_stat").toString();
            currentSkill.skillLevel = t_currentSkillJson.value("skill_level").toInt();
            m_skills.insert(currentSkill.skillName, currentSkill);
        }
    }
}

QJsonObject RpgCharacter::serialize()
{
    QJsonObject t_returnObject;
    QJsonObject t_contentsObject;
    t_contentsObject.insert("max_health_points", maxHealthPoints());
    t_contentsObject.insert("health_points", healthPoints());
    t_contentsObject.insert("character_level", level());
    t_contentsObject.insert("max_experience_points", experiencePointsNeeded());
    t_contentsObject.insert("experience_points", experiencePoints());
    QJsonObject t_hitDice;
    t_hitDice.insert("diceAmount", hitDice().diceAmount);
    t_hitDice.insert("diceSides", hitDice().diceSides);

    t_contentsObject.insert("hit_dice", t_hitDice);

    QJsonObject t_statsObject;
    QStringList t_statsKeys = m_stats.keys();
    for(const QString &key : t_statsKeys)
    {
        t_statsObject.insert(key, m_stats.value(key));
    }
    t_contentsObject.insert("stats", t_statsObject);

    QJsonObject t_skillsObject;
    QStringList t_skillsKeys = m_skills.keys();
    for(const QString &key : t_skillsKeys)
    {
        Skill currentSkill = m_skills.value(key);
        QJsonObject t_currentSkillObject;
        t_currentSkillObject.insert("skill_stat", currentSkill.skillStat);
        t_currentSkillObject.insert("skill_level", currentSkill.skillLevel);
        t_skillsObject.insert(currentSkill.skillName, t_currentSkillObject);
    }
    t_contentsObject.insert("skills", t_skillsObject);

    t_returnObject.insert("contents", t_contentsObject);
    t_returnObject.insert("type", "character");

    return t_returnObject;
}

int RpgCharacter::healthPoints() const
{
    return m_healthPoints;
}

void RpgCharacter::setHealthPoints(int p_healthPoints)
{
    if(p_healthPoints == m_healthPoints)
        return;
    m_healthPoints = p_healthPoints;
    emit healthPointsChanged();
}

void RpgCharacter::healCharacter(int p_healedHealthPoints)
{
    int p_hpToHeal = p_healedHealthPoints;
    if((healthPoints() + p_healedHealthPoints) > maxHealthPoints())
    {
        setHealthPoints(maxHealthPoints());
        return;
    }
    setHealthPoints(healthPoints() + p_hpToHeal);
}

int RpgCharacter::maxHealthPoints() const
{
    return m_maxHealthPoints;
}

void RpgCharacter::setMaxHealthPoints(int p_maxHealthPoints)
{
    m_maxHealthPoints = p_maxHealthPoints;
}

void RpgCharacter::increaseMaxHealthPoints(int p_additionalMaxHealth)
{
    setMaxHealthPoints(maxHealthPoints() + p_additionalMaxHealth);
}

int RpgCharacter::level() const
{
    return m_level;
}

void RpgCharacter::setLevel(int p_level)
{
    if(m_level == p_level)
        return;
    m_level = p_level;
    emit levelChanged();
}

void RpgCharacter::levelUp()
{
    setLevel(level() + 1);
}

int RpgCharacter::experiencePoints() const
{
    return m_experiencePoints;
}

void RpgCharacter::setExperiencePoints(int p_experiencePoints)
{
    m_experiencePoints = p_experiencePoints;
    if(experiencePoints() >= experiencePointsNeeded())
    {
        levelUp();
        m_experiencePoints = 0;
    }
}

void RpgCharacter::addExperiencePoints(int p_additionalPoints)
{
    setExperiencePoints(experiencePoints() + p_additionalPoints);
}

int RpgCharacter::experiencePointsNeeded() const
{
    return m_experiencePointsNeeded;
}

void RpgCharacter::setExperiencePointsNeeded(int p_pointsNeeded)
{
    m_experiencePointsNeeded = p_pointsNeeded;
}


int RpgCharacter::strength()
{
    return stats().value("strength", 0);
}

int RpgCharacter::dexterity()
{
    return stats().value("dexterity", 0);
}

int RpgCharacter::constitution()
{
    return stats().value("constitution", 0);
}

int RpgCharacter::intelligence()
{
    return stats().value("intelligence", 0);
}

int RpgCharacter::wisdom()
{
    return stats().value("wisdom", 0);
}

int RpgCharacter::charisma()
{
    return stats().value("charisma", 0);
}

RpgCharacter::Dice RpgCharacter::hitDice() const
{
    return m_hitDice;
}

void RpgCharacter::setHitDice(RpgCharacter::Dice p_hitDice)
{
    m_hitDice = p_hitDice;
}


int RpgCharacter::armorClass() const
{
    return m_armorClass;
}

void RpgCharacter::setArmorClass(int p_armorClass)
{
    m_armorClass = p_armorClass;
}

QHash<QString, int> RpgCharacter::stats() const
{
    return m_stats;
}

QHash<QString, RpgCharacter::Skill> RpgCharacter::skills() const
{
    return m_skills;
}

RpgPlayer_ptr RpgCharacter::characterPlayer() const
{
    return m_characterPlayer;
}

void RpgCharacter::setCharacterPlayer(const RpgPlayer_ptr &p_characterPlayer)
{
    m_characterPlayer = p_characterPlayer;
    if(p_characterPlayer->playerCharacter() != thisCharacter())
        p_characterPlayer->setPlayerCharacter(thisCharacter());
}

RpgCharacter::RpgCharacter_ptr RpgCharacter::thisCharacter()
{
    return RpgCharacter_ptr(this);
}

} // namespace TableTopLib

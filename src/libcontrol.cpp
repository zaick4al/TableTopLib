#include "libcontrol.h"
namespace TableTopLib {
LibControl &LibControl::instance()
{
    static LibControl libControlInstance;
    return libControlInstance;
}

QList<int> LibControl::rollTheDice(int p_dieSides, int p_dieAmount)
{
    m_dice->setDieSides(p_dieSides);
    return m_dice->rollTheDice(p_dieAmount);
}

LibControl::LibControl(QObject *parent)
    : QObject{parent}
{
    m_dice = createObject<Die>(0);
}

template<typename T>
std::shared_ptr<T> LibControl::getOrAdd(long long p_id)
{
    if(std::is_same_v<T, Player>)
    {
        if(m_players.contains(p_id))
            return m_players.value(p_id);
        m_players.insert(p_id, createObject<Player>(p_id));
        return m_players.value(p_id);
    }
    else if(std::is_same_v<T, RpgCharacter>)
    {
        if(m_rpgCharacters.contains(p_id))
            return m_rpgCharacters.value(p_id);
        m_rpgCharacters.insert(p_id, createObject<RpgCharacter>(p_id));
        return m_rpgCharacters.value(p_id);
    }
    else if(std::is_same_v<T, RpgCurrency>){
        if(m_rpgCurrencies.contains(p_id))
            return m_rpgCurrencies.value(p_id);
        m_rpgCurrencies.insert(p_id, createObject<RpgCurrency>(p_id));
        return m_rpgCurrencies.value(p_id);
    }
    else if(std::is_same_v<T, RpgPlayer>){
        if(m_rpgPlayers.contains(p_id))
            return m_rpgPlayers.value(p_id);
        m_rpgPlayers.insert(p_id, createObject<RpgPlayer>(p_id));
        return m_rpgPlayers.value(p_id);
    }
    else if(std::is_same_v<T, DndPlayer>){
        if(m_dndPlayers.contains(p_id))
            return m_dndPlayers.value(p_id);
        m_dndPlayers.insert(p_id, createObject<DndPlayer>(p_id));
        return m_dndPlayers.value(p_id);
    }
    else if(std::is_same_v<T, DndCharacter>){
        if(m_dndCharacters.contains(p_id))
            return m_dndCharacters.value(p_id);
        m_dndCharacters.insert(p_id, createObject<DndCharacter>(p_id));
        return m_dndCharacters.value(p_id);
    }
    return nullptr;
}

template<typename T>
std::shared_ptr<T> LibControl::createObject(long long p_id)
{
    return std::make_shared<T>(p_id);
}

template<typename T>
std::shared_ptr<T> LibControl::get(long long p_id)
{
    if(std::is_same_v<T, Player_ptr>)
    {
        if(m_players.contains(p_id))
            return m_players.value(p_id);
    }
    else if(std::is_same_v<T, RpgCharacter>)
    {
        if(m_rpgCharacters.contains(p_id))
            return m_rpgCharacters.value(p_id);
    }
    else if(std::is_same_v<T, RpgCurrency>){
        if(m_rpgCurrencies.contains(p_id))
            return m_rpgCurrencies.value(p_id);
    }
    else if(std::is_same_v<T, RpgPlayer>){
        if(m_rpgPlayers.contains(p_id))
            return m_rpgPlayers.value(p_id);
    }
    else if(std::is_same_v<T, DndPlayer>){
        if(m_dndPlayers.contains(p_id))
            return m_dndPlayers.value(p_id);
    }
    else if(std::is_same_v<T, DndCharacter>){
        if(m_dndCharacters.contains(p_id))
            return m_dndCharacters.value(p_id);
    }
    return nullptr;
}

template<typename T>
void LibControl::remove(std::shared_ptr<T> p_object)
{
    if(std::is_same_v<T, Player_ptr>)
    {
        emit p_object->removePending();
        if(m_players.contains(p_object->id()))
            m_players.remove(p_object->id());
    }
    else if(std::is_same_v<T, RpgCharacter>)
    {
        emit p_object->removePending();
        if(m_rpgCharacters.contains(p_object->id()))
            return m_rpgCharacters.value(p_object->id());
    }
    else if(std::is_same_v<T, RpgCurrency>){
        emit p_object->removePending();
        if(m_rpgCurrencies.contains(p_object->id()))
            return m_rpgCurrencies.value(p_object->id());
    }
    else if(std::is_same_v<T, RpgPlayer>){
        emit p_object->removePending();
        if(m_rpgPlayers.contains(p_object->id()))
            return m_rpgPlayers.value(p_object->id());
    }
    else if(std::is_same_v<T, DndPlayer>){
        emit p_object->removePending();
        if(m_dndPlayers.contains(p_object->id()))
            return m_dndPlayers.value(p_object->id());
    }
    else if(std::is_same_v<T, DndCharacter>){
        emit p_object->removePending();
        if(m_dndCharacters.contains(p_object->id()))
            return m_dndCharacters.value(p_object->id());
    }

}

}

#include "player.h"

namespace TableTopLib {

Player::Player(long long p_id, QObject *parent)
    : TableTopLib::TableTopObject{parent}, m_playerLoggedIn(false)
{
    setId(p_id);
}

void Player::deserialize(const QJsonObject &p_jsonObject)
{
    if(p_jsonObject.contains("player_name"))
    {
        setPlayerName(p_jsonObject.value("player_name").toString());
        setPlayerLoggedIn(true);
    }
}

QString Player::playerName() const
{
    return m_playerName;
}

void Player::setPlayerName(const QString &p_playerName)
{
    m_playerName = p_playerName;
}

bool Player::playerLoggedIn() const
{
    return m_playerLoggedIn;
}

void Player::setPlayerLoggedIn(bool p_playerLoggedIn)
{
    m_playerLoggedIn = p_playerLoggedIn;
}

Player::Player_ptr Player::thisPlayer()
{
    return Player_ptr(this);
}

} // namespace TableTopLib

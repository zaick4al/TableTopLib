#ifndef TABLETOPLIB_PLAYER_H
#define TABLETOPLIB_PLAYER_H

#include <tabletopobject.h>
#include <QJsonObject>

namespace TableTopLib {
/**
 * @brief The Player class
 * Abstract template for custom player classes
 */
class TABLETOPLIB_EXPORT Player : public TableTopLib::TableTopObject
{
    Q_OBJECT
    typedef std::shared_ptr<Player> Player_ptr;
public:
    /**
     * @brief Player
     * @param p_id - id of a created object
     * @param parent
     * Constructor of Player object
     */
    explicit Player(long long p_id, QObject *parent = nullptr);

    /**
     * @brief serialize
     * @return QJsonObject - serialized date
     * Serialize to json method of player's class
     */
    virtual const QJsonObject serialize();

    /**
     * @brief deserialize
     * @param p_jsonObject - QJsonObject
     * Deserialize from json method of Player class
     */
    virtual void deserialize(const QJsonObject &p_jsonObject);

    /**
     * @brief playerName
     * @return QString - name of this instance's player
     * Getter method of player's name
     */
    QString playerName() const;
    /**
     * @brief setPlayerName
     * @param p_playerName - const QString & name of this instance's player
     * Setter method of player's name
     */
    void setPlayerName(const QString &p_playerName);

    /**
     * @brief playerLoggedIn
     * @return bool - isPlayerLoggedIn
     * Getter of current player's auth state
     */
    bool playerLoggedIn() const;

    /**
     * @brief setPlayerLoggedIn
     * @param p_playerLoggedIn - player's auth state
     * Setter of current player's auth state
     */
    void setPlayerLoggedIn(bool p_playerLoggedIn);

protected:
    /**
     * @private
     */
    QString m_playerName;
    /**
     * @private
     */
    bool m_playerLoggedIn;
};
typedef std::shared_ptr<Player> Player_ptr;

} // namespace TableTopLib

#endif // TABLETOPLIB_PLAYER_H

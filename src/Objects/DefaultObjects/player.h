#ifndef TABLETOPLIB_PLAYER_H
#define TABLETOPLIB_PLAYER_H

#include <tabletopobject.h>
#include <QJsonObject>

namespace TableTopLib {

class TABLETOPLIB_EXPORT Player : public TableTopLib::TableTopObject
{
    Q_OBJECT
    typedef std::shared_ptr<Player> Player_ptr;
public:
    explicit Player(long long p_id, QObject *parent = nullptr);

    virtual void deserialize(const QJsonObject &p_jsonObject);


    QString playerName() const;
    void setPlayerName(const QString &p_playerName);

    bool playerLoggedIn() const;
    void setPlayerLoggedIn(bool p_playerLoggedIn);

    Player_ptr thisPlayer();

protected:
    QString m_playerName;
    bool m_playerLoggedIn;
};
typedef std::shared_ptr<Player> Player_ptr;

} // namespace TableTopLib

#endif // TABLETOPLIB_PLAYER_H

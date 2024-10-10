#ifndef LIBCONTROL_H
#define LIBCONTROL_H

#include <QObject>
#include <DefaultObjects/die.h>
#include <DefaultObjects/player.h>
#include <RpgObjects/rpgcharacter.h>
#include <RpgObjects/rpgcurrency.h>
#include <RpgObjects/rpgplayer.h>
#include <DndObjects/dndplayer.h>
#include <DndObjects/dndcharacter.h>
namespace TableTopLib {
class TABLETOPLIB_EXPORT LibControl : public QObject
{
    Q_OBJECT
public:
    static LibControl &instance();
    QList<int> rollTheDice(int p_dieSides = 20, int p_dieAmount = 1);
    template <typename T>
    std::shared_ptr<T> getOrAdd(long long p_id);
    template <typename T>
    std::shared_ptr<T> get(long long p_id);
    template <typename T>
    void remove(std::shared_ptr<T> p_object);
signals:

protected:
    explicit LibControl(QObject *parent = nullptr);
    template <typename T>
    std::shared_ptr<T> createObject(long long p_id);

private:
    Dice_ptr m_dice;
    QHash<long long, Player_ptr> m_players;
    QHash<long long, RpgCharacter_ptr> m_rpgCharacters;
    QHash<long long, RpgCurrency_ptr> m_rpgCurrencies;
    QHash<long long, RpgPlayer_ptr> m_rpgPlayers;
    QHash<long long, DndPlayer_ptr> m_dndPlayers;
    QHash<long long, DndCharacter_ptr> m_dndCharacters;
};
}
//typedef TableTopLib::LibControl::instance() TABLETOP;
#endif // LIBCONTROL_H

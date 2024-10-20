#ifndef LIBCONTROL_H
#define LIBCONTROL_H

#include <QObject>
#include <tabletopobject.h>
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
    std::shared_ptr<T> getOrAdd(std::shared_ptr<T> p_object);
    template <typename T>
    std::shared_ptr<T> getOrAdd(std::weak_ptr<T> p_objectWeak);
    template <typename T>
    std::shared_ptr<T> getOrAdd(T* p_rawPointer);


    template <typename T>
    std::shared_ptr<T> get(long long p_id);
    template <typename T>
    std::shared_ptr<T> get(std::shared_ptr<T> p_object);
    template <typename T>
    std::shared_ptr<T> get(std::weak_ptr<T> p_objectWeak);
    template <typename T>
    std::shared_ptr<T> get(T* p_rawPointer);

    template <typename T>
    void remove(long long p_id);
    template <typename T>
    void remove(std::shared_ptr<T> p_object);
    template <typename T>
    void remove(std::weak_ptr<T> p_objectWeak);
    template <typename T>
    void remove(T* p_rawPointer);
signals:

protected:
    explicit LibControl(QObject *parent = nullptr);
    template <typename T>
    std::shared_ptr<T> createObject(long long p_id);

private:
    Dice_ptr m_dice;
    QHash<long long, TableTopObject_ptr> m_objects;
};
}
//typedef TableTopLib::LibControl::instance() TABLETOP;
#endif // LIBCONTROL_H

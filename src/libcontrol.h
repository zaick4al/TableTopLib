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
/**
 * @brief The LibControl class
 * Singleton that let's you manage objects easily with methods to add, remove and get objects as std::shared_ptrs
 */
class TABLETOPLIB_EXPORT LibControl : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief LibControl
     * @return &LibControl
     * LibControl singleton instance call
     */
    static LibControl &instance();

    /**
     * @brief Rolling the dice
     * @param p_dieSides - argument that lets you dice d{what} are you rolling (default = 20{d20})
     * @param p_dieAmount - argument that lets you roll multiple dice (default = 1)
     * @return
     */
    QList<int> rollTheDice(int p_dieSides = 20, int p_dieAmount = 1);

    /**
     * @brief getOrAdd
     * Method lets you get or add object, that is derived from TableTopLibObject by object's id.
     * If object exists in the lib's internal QHash - it would return you that object. In other case it'll create a new one, add it to QHash and return it
     * @param p_id - long long id of object needed to return
     * @return std::shared_ptr<T>, where T is class derived from TableTopLibObject.
     */
    template <typename T>
    std::shared_ptr<T> getOrAdd(long long p_id);
    /**
     * @brief getOrAdd
     * Method lets you get or add object, that is derived from TableTopLibObject by object's STL shared pointer.
     * If object exists in the lib's internal QHash - it would return you that object. In other case it'll create a new one, add it to QHash and return it
     * @param p_object - std::shared_ptr<T> of object needed to return
     * @return std::shared_ptr<T>, where T is class derived from TableTopLibObject.
     */
    template <typename T>
    std::shared_ptr<T> getOrAdd(std::shared_ptr<T> p_object);
    /**
     * @brief getOrAdd
     * Method lets you get or add object, that is derived from TableTopLibObject by object's STL weak pointer.
     * If object exists in the lib's internal QHash - it would return you that object. In other case it'll create a new one, add it to QHash and return it
     * @param p_objectWeak - std::weak_ptr<T> of object needed to return
     * @return std::shared_ptr<T>, where T is class derived from TableTopLibObject.
     */
    template <typename T>
    std::shared_ptr<T> getOrAdd(std::weak_ptr<T> p_objectWeak);
    /**
     * @brief getOrAdd
     * Method lets you get or add object, that is derived from TableTopLibObject by object's raw pointer.
     * If object exists in the lib's internal QHash - it would return you that object. In other case it'll create a new one, add it to QHash and return it
     * @param p_rawPointer - raw pointer of object needed to return
     * @return std::shared_ptr<T>, where T is class derived from TableTopLibObject.
     */
    template <typename T>
    std::shared_ptr<T> getOrAdd(T* p_rawPointer);

    /**
     * @brief get
     * Method lets you get object, that is derived from TableTopLibObject and stored in lib's internal QHash by object's id.
     * @param p_id - long long id of object needed to return
     * @return std::shared_ptr<T>, where T is class derived from TableTopLibObject.
     */
    template <typename T>
    std::shared_ptr<T> get(long long p_id);
    /**
     * @brief get
     * Method lets you get object, that is derived from TableTopLibObject and stored in lib's internal QHash by object's STL shared pointer.
     * @param p_object - std::shared_ptr<T> of object needed to return
     * @return std::shared_ptr<T>, where T is class derived from TableTopLibObject.
     */
    template <typename T>
    std::shared_ptr<T> get(std::shared_ptr<T> p_object);
    /**
     * @brief get
     * Method lets you get object, that is derived from TableTopLibObject and stored in lib's internal QHash by object's STL weak pointer.
     * @param p_objectWeak - std::weak_ptr<T> of object needed to return
     * @return std::shared_ptr<T>, where T is class derived from TableTopLibObject.
     */
    template <typename T>
    std::shared_ptr<T> get(std::weak_ptr<T> p_objectWeak);
    /**
     * @brief get
     * Method lets you get object, that is derived from TableTopLibObject and stored in lib's internal QHash by object's raw pointer.
     * @param p_rawPointer - raw pointer of object needed to return
     * @return std::shared_ptr<T>, where T is class derived from TableTopLibObject.
     */
    template <typename T>
    std::shared_ptr<T> get(T* p_rawPointer);

    /**
     * @brief remove
     * Method lets you remove object stored in lib's internal QHash by object's id.
     * @param p_id - long long id of object that is derived of TableTopObject and stored in QHash
     */
    template <typename T>
    void remove(long long p_id);
    /**
     * @brief remove
     * Method lets you remove object stored in lib's internal QHash by object's STL shared pointer.
     * @param p_object - std::shared_ptr<T> of object that is derived of TableTopObject and stored in QHash
     */
    template <typename T>
    void remove(std::shared_ptr<T> p_object);
    /**
     * @brief remove
     * Method lets you remove object stored in lib's internal QHash by object's STL weak pointer.
     * @param p_objectWeak - std::weak_ptr<T> of object that is derived of TableTopObject and stored in QHash
     */
    template <typename T>
    void remove(std::weak_ptr<T> p_objectWeak);

    /**
     * @brief remove
     * Method lets you remove object stored in lib's internal QHash by object's raw pointer.
     * @param p_rawPointer - raw pointer of object that is derived of TableTopObject and stored in QHash
     */
    template <typename T>
    void remove(T* p_rawPointer);
signals:

protected:
    /**
     * @private
     */
    explicit LibControl(QObject *parent = nullptr);
    /**
     * @private
     */
    template <typename T>
    std::shared_ptr<T> createObject(long long p_id);

private:
    /**
     * @private
     */
    Dice_ptr m_dice;
    /**
     * @private
     */
    QHash<long long, TableTopObject_ptr> m_objects;
};
}
//typedef TableTopLib::LibControl::instance() TABLETOP;
#endif // LIBCONTROL_H

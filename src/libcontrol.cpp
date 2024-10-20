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
    m_dice = getOrAdd<Die>((long long)0);
}

template<typename T>
std::shared_ptr<T> LibControl::createObject(long long p_id)
{
    if(!std::is_convertible_v<T, TableTopObject>)
        return nullptr;
    auto createdObject = std::make_shared<T>(p_id);
    connect(createdObject.get(), &TableTopObject::removePending, this, [=](){
        remove<T>(createdObject->id());
    });
    m_objects.insert(p_id, createdObject);
}

template<typename T>
std::shared_ptr<T> LibControl::getOrAdd(long long p_id)
{
    if(!std::is_convertible_v<T, TableTopObject>)
        return nullptr;
    auto gotObject = get<T>(p_id);
    if(gotObject)
        return gotObject;

    return createObject<T>(p_id);
}

template<typename T>
std::shared_ptr<T> LibControl::getOrAdd(std::shared_ptr<T> p_object)
{
    long long id = p_object->id();
    return getOrAdd<T>(id);
}

template<typename T>
std::shared_ptr<T> LibControl::getOrAdd(std::weak_ptr<T> p_objectWeak)
{
    long long id = p_objectWeak.lock()->id();
    return getOrAdd<T>(id);
}

template<typename T>
std::shared_ptr<T> LibControl::getOrAdd(T *p_rawPointer)
{
    if(p_rawPointer)
        return getOrAdd(p_rawPointer->id());
}


template<typename T>
std::shared_ptr<T> LibControl::get(long long p_id)
{
    if(!std::is_convertible_v<T, TableTopObject>)
        return nullptr;
    if(m_objects.contains(p_id))
        return std::dynamic_pointer_cast<T>(m_objects.value(p_id));
    return nullptr;
}

template<typename T>
std::shared_ptr<T> LibControl::get(std::shared_ptr<T> p_object)
{
    return get(p_object->id());
}

template<typename T>
std::shared_ptr<T> LibControl::get(std::weak_ptr<T> p_objectWeak)
{
    return get(p_objectWeak.lock()->id());
}

template<typename T>
std::shared_ptr<T> LibControl::get(T *p_rawPointer)
{
    if(p_rawPointer)
        return get(p_rawPointer->id());
    return nullptr;
}


template<typename T>
void LibControl::remove(long long p_id)
{
    if(!std::is_convertible_v<T, TableTopObject>)
        return;
    TableTopObject_ptr sharedObject = get<T>(p_id);
    if(!sharedObject)
        return;
    emit sharedObject->removePending();

}

template<typename T>
void LibControl::remove(std::shared_ptr<T> p_object)
{
    remove(p_object->id());
}

template<typename T>
void LibControl::remove(std::weak_ptr<T> p_objectWeak)
{
    remove(p_objectWeak.lock()->id());
}

template<typename T>
void LibControl::remove(T *p_rawPointer)
{
    if(p_rawPointer)
        remove(p_rawPointer->id());
}
}

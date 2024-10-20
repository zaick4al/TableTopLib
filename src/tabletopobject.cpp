#include "tabletopobject.h"

namespace TableTopLib{

TableTopObject::TableTopObject(QObject *parent)
{

}

TableTopObject::~TableTopObject()
{

}

long long TableTopObject::id() const
{
    return m_id;
}

void TableTopObject::setId(const long long &p_id)
{
    if(m_id == p_id)
        return;
    m_id = p_id;
}


}

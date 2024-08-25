#include "tabletopobject.h"

namespace TableTopLib{

TableTopObject::TableTopObject(QObject *parent)
{

}

TableTopObject::~TableTopObject()
{

}

QString TableTopObject::id() const
{
    return m_id;
}

void TableTopObject::setId(const QString &p_id)
{
    if(m_id == p_id)
        return;
    emit idChanged();
    m_id = p_id;
}


}

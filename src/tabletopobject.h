#ifndef TABLETOPOBJECT_H
#define TABLETOPOBJECT_H

#include "TableTopLib_global.h"
#include <QObject>

namespace TableTopLib{
/**
 * @brief The TableTopObject class
 * Abstract template class for custom library objects
 */
class TABLETOPLIB_EXPORT TableTopObject : public QObject{
    Q_OBJECT
public:
    /**
     * @brief TableTopObject
     * @param parent
     * Constructor
     */
    explicit TableTopObject(QObject *parent = nullptr);
    /**
     * @private
     */
    ~TableTopObject();
    /**
     * @brief id
     * @return long long
     * Getter of object's id
     */
    virtual long long id() const;
    /**
     * @brief setId
     * @param p_id - long long
     * Setter of object's id
     */
    virtual void setId(const long long &p_id);

signals:
    /**
     * @brief removePending
     * Signal notifying that object is going to be removed from library's singleton shortly
     */
    void removePending();

protected:
    /**
     * @brief @private
     */
    long long m_id;
};
typedef std::shared_ptr<TableTopObject> TableTopObject_ptr;
} //namespace TableTopLib

#endif // TABLETOPOBJECT_H

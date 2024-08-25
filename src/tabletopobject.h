#ifndef TABLETOPOBJECT_H
#define TABLETOPOBJECT_H

#include "TableTopLib_global.h"
#include <QObject>

namespace TableTopLib{
class TABLETOPLIB_EXPORT TableTopObject : public QObject{
    Q_OBJECT
public:
    explicit TableTopObject(QObject *parent = nullptr);
    ~TableTopObject();
    virtual QString id() const;
    virtual void setId(const QString &p_id);

signals:
    void idChanged();

protected:
    QString m_id;
};
} //namespace TableTopLib

#endif // TABLETOPOBJECT_H

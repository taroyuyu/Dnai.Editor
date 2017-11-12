#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QFile>
#include <QJsonObject>
#include "models/class.h"
#include "models/context.h"
#include "models/flow.h"
#include "models/function.h"
#include "models/input.h"
#include "models/output.h"
#include "models/node.h"
#include "models/variable.h"
#include "models/imodel.h"

namespace duly_gui {
struct Count {
    int contexts = 0;
    int classes = 0;
    int nodes = 0;
    int functions = 0;
    int variables = 0;
    int inputs = 0;
    int outputs = 0;
    int flows = 0;
};
}

namespace duly_gui {
    class Project: public models::Common, virtual public models::IModel
    {
    public:
        Project(const QString &, const QString &, QFile &);
        virtual ~Project();

        typedef bool (* searchFunc)(models::Common *, QString const &);
        typedef bool (* searchFunctionsFunc)(models::Function *, QString const &);

    public:
        void save();

    private:
        QFile &m_file;

        QVector<models::Common*> m_index;
        QVector<models::Function*> m_functions_index;

        models::Context const *m_main;

        Count count;

    public:
        QFile &file() const;
        QJsonObject data() const;

    private:
        models::Variable *unserializeVariable(const QJsonObject &);
        models::Input *unserializeInput(const QJsonObject &);
        models::Output *unserializeOutput(const QJsonObject &);
        models::Flow *unserializeFlow(const QJsonObject &);
        models::Function *unserializeFunction(const QJsonObject &, models::Context *);
        models::Class *unserializeClass(const QJsonObject &, models::Context *);
        models::Context *unserializeContext(const QJsonObject &, models::Context *);
        models::Node *unserializeNode(const QJsonObject &, models::Function *);


        // IModel interface
    public:
        virtual void serialize(QJsonObject &) const;

    public:
        void unserialize(const QJsonObject &);
        QVector<models::Common*> search(QString const &, searchFunc = defaultSearchFunc);
        QVector<models::Function*> searchFunctions(QString const &, searchFunctionsFunc = defaultSearchFunctionsFunc);

    private:
        static bool defaultSearchFunc(models::Common *, QString const &);
        static bool defaultSearchFunctionsFunc(models::Function *, QString const &);

    };
}

#endif // PROJECT_H

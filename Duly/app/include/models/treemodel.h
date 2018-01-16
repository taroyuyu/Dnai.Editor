#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include "project.h"


namespace duly_gui {
namespace models {
class TreeItem;

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit TreeModel(QObject *parent = nullptr) : QAbstractItemModel(parent) {}
    TreeModel(const Project *project, QObject *parent = 0);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    void setupModelData(const Project *project, TreeItem *parent);
    void setupContextModel(const models::Context *context, TreeItem *parent, int currentIdx);
    void setupClassModel(const models::Class *cl, TreeItem *parent, int currentIdx);
    void setupFunctionModel(const models::Function *func, TreeItem *parent, int currentIdx);

    TreeItem *rootItem;
};
}
}

Q_DECLARE_METATYPE(duly_gui::models::TreeModel*)


#endif // TREEMODEL_H
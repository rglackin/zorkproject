#ifndef INVENTORYWINDOW_H
#define INVENTORYWINDOW_H
#include <QDialog>
#include "item.h"
namespace Ui {
class inventoryWindow;
}

class inventoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit inventoryWindow(QWidget *parent = nullptr);
    ~inventoryWindow();

private slots:
    void on_btnExit_clicked();
    void populateInv();
    void on_tbl_items_itemSelectionChanged();
    void displayItem(Item* i);
    void on_btnShowTable_clicked();
    void setItemViewVisibility(bool visible);
private:
    Ui::inventoryWindow *ui;
};

#endif // INVENTORYWINDOW_H

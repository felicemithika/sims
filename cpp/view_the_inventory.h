#ifndef VIEW_THE_INVENTORY_H
#define VIEW_THE_INVENTORY_H

#include "../build/ui_the_current_inventory.h"
#include <QWidget>

class view_items_in_the_inventory_Form : public QWidget {
    Q_OBJECT

    public:
        explicit view_items_in_the_inventory_Form(QWidget* parent = nullptr);

    private:
        Ui::view_items_in_the_inventory_Form ui;
};

#endif
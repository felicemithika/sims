#ifndef VIEW_CREATED_BATCHES_H
#define VIEW_CREATED_BATCHES_H

#include "../build/ui_view_all_created_batches.h"
#include <QWidget>

class view_created_batches : public QWidget {
    Q_OBJECT

    public:
        explicit view_created_batches(QWidget* parent = nullptr);
    
    private:
        Ui::view_created_batches ui;

};

#endif
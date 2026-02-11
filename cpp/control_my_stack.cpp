#include "control_my_stack.h"

/*MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
        stack = new QStackedWidget(this);
        setCentralWidget(stack);

        MainWindow = new MainWindow(this);

        //login->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        stack->addWidget(MainWindow);
        //stack->addWidget(login);

        stack->setCurrentWidget(welcome);

        connect(welcome, &LoginScreen::finished, this, [this]() {
            stack->setCurrentWidget(login);
            this->adjustSize();
        });
    }*/
#ifndef WELCOME_SCREEN_H
#define WELCOME_SCREEN_H

#include <QWidget>
#include <QTimer>
#include "../build/ui_welcome-screen.h"

class WelcomeScreen : public QWidget {
    Q_OBJECT

    public:
        explicit WelcomeScreen(QWidget *parent = nullptr);
    
    signals:
        void finished();
    
    private:
        Ui::welcome_screen ui;
        QTimer *progressTimer;
        int progressValue;

        void cache_user_data();
};

#endif
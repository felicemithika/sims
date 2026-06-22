// Include welcome screens header file.
#include "welcome-screen.h"

WelcomeScreen::WelcomeScreen(QWidget *parent) : QWidget(parent), progressValue(0) {
    this->setObjectName("welcome_screen");
    ui.setupUi(this);


    progressTimer = new QTimer(this);

    connect(progressTimer, &QTimer::timeout, [this]() {
        progressValue++;
        ui.progressBar->setValue(progressValue);

        if (progressValue >= 100) {
            progressTimer->stop();
            cache_user_data();
            emit finished();
            this->close();
        }
    });

    progressTimer->start(50);
}

void WelcomeScreen::cache_user_data() {
    //TODO: add this logic later
}
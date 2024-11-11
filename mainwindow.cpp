#include "./ui_mainwindow.h"
#include "Deck.h"
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto centralWidget = new QWidget(this);

    auto layout = new QVBoxLayout(centralWidget);

    createButton = new QPushButton("Create Deck");
    studyButton = new QPushButton("Study Deck");

    layout->addWidget(createButton);
    layout->addWidget(studyButton);

    setCentralWidget(centralWidget);

    connect(createButton, &QPushButton::pressed, this,
            [&](){createWindow = new QWidget; createWindow->show(); });
    connect(studyButton, &QPushButton::pressed, this,
            [&](){studyWindow = new QWidget; studyWindow->show(); });

}

MainWindow::~MainWindow()
{
    delete ui;
}



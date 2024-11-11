#include "./ui_mainwindow.h"
#include "Deck.h"
#include "mainwindow.h"
#include "createwindow.h"
#include "studywindow.h"


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

    // TODO: FIX MULTIPLE WINDOWS OPENING WHEN CLICKING MORE THAN ONCE
    connect(createButton, &QPushButton::pressed, this,
            [](){ CreateWindow c; } );

    connect(studyButton, &QPushButton::pressed, this,
            [](){ StudyWindow s; } );

}

MainWindow::~MainWindow()
{
    delete ui;
}



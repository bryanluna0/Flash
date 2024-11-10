#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include "Deck.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto centralWidget = new QWidget(this);

    auto layout = new QVBoxLayout(centralWidget);

    auto createButton = new QPushButton("Create Deck");
    layout->addWidget(createButton);

    auto studyButton = new QPushButton("Study Deck");
    layout->addWidget(studyButton);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}



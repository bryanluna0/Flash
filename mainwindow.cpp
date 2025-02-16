/* The specification file for the class of the main window.
 * This is the main window that will direct the user to
 * the different functionalities of the flashcard app
 * such as the create and study windows.
 *
 */

#include "./ui_mainwindow.h"
#include "deck.h"
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
            [this](){ CreateWindow c(decks); } );

    connect(studyButton, &QPushButton::pressed, this,
            [this](){ StudyWindow s(decks); } );

}

MainWindow::~MainWindow()
{
    delete ui;
}



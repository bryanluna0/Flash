/* The specification file for the class of the main window.
 * This is the main window that will direct the user to
 * the different functionalities of the flashcard app
 * such as the create and study windows.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "deck.h"
#include <QMainWindow>
#include <QPushButton>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    std::vector<Deck> decks;

    QPushButton* createButton;
    QPushButton* studyButton;

    QWidget* createWindow;
    QWidget* studyWindow;
};
#endif // MAINWINDOW_H

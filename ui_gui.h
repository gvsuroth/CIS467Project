/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created: Tue Nov 16 08:02:40 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gui
{
public:
    QAction *action_Reset;
    QAction *action_Dimensions;
    QAction *action_Zoom_In;
    QAction *action_Zoom_Out;
    QAction *action_Prim_s_Algorithm;
    QAction *action_Right_Hand_Rule;
    QAction *action_Back_and_Forth;
    QAction *action_Backtracker_Algorithm;
    QAction *action_Dead_End_Filler;
    QAction *action_Braid_Maze;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_View;
    QMenu *menu_Maze;
    QMenu *menu_Generator;
    QMenu *menu_Solve;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Gui)
    {
        if (Gui->objectName().isEmpty())
            Gui->setObjectName(QString::fromUtf8("Gui"));
        Gui->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Gui->sizePolicy().hasHeightForWidth());
        Gui->setSizePolicy(sizePolicy);
        action_Reset = new QAction(Gui);
        action_Reset->setObjectName(QString::fromUtf8("action_Reset"));
        action_Dimensions = new QAction(Gui);
        action_Dimensions->setObjectName(QString::fromUtf8("action_Dimensions"));
        action_Zoom_In = new QAction(Gui);
        action_Zoom_In->setObjectName(QString::fromUtf8("action_Zoom_In"));
        action_Zoom_Out = new QAction(Gui);
        action_Zoom_Out->setObjectName(QString::fromUtf8("action_Zoom_Out"));
        action_Prim_s_Algorithm = new QAction(Gui);
        action_Prim_s_Algorithm->setObjectName(QString::fromUtf8("action_Prim_s_Algorithm"));
        action_Right_Hand_Rule = new QAction(Gui);
        action_Right_Hand_Rule->setObjectName(QString::fromUtf8("action_Right_Hand_Rule"));
        action_Back_and_Forth = new QAction(Gui);
        action_Back_and_Forth->setObjectName(QString::fromUtf8("action_Back_and_Forth"));
        action_Backtracker_Algorithm = new QAction(Gui);
        action_Backtracker_Algorithm->setObjectName(QString::fromUtf8("action_Backtracker_Algorithm"));
        action_Dead_End_Filler = new QAction(Gui);
        action_Dead_End_Filler->setObjectName(QString::fromUtf8("action_Dead_End_Filler"));
        action_Braid_Maze = new QAction(Gui);
        action_Braid_Maze->setObjectName(QString::fromUtf8("action_Braid_Maze"));
        centralWidget = new QWidget(Gui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Gui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Gui);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        menu_Maze = new QMenu(menuBar);
        menu_Maze->setObjectName(QString::fromUtf8("menu_Maze"));
        menu_Generator = new QMenu(menuBar);
        menu_Generator->setObjectName(QString::fromUtf8("menu_Generator"));
        menu_Solve = new QMenu(menuBar);
        menu_Solve->setObjectName(QString::fromUtf8("menu_Solve"));
        Gui->setMenuBar(menuBar);
        statusBar = new QStatusBar(Gui);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Gui->setStatusBar(statusBar);

        menuBar->addAction(menu_Maze->menuAction());
        menuBar->addAction(menu_Generator->menuAction());
        menuBar->addAction(menu_Solve->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menu_View->addAction(action_Zoom_In);
        menu_View->addAction(action_Zoom_Out);
        menu_View->addAction(action_Reset);
        menu_Maze->addAction(action_Dimensions);
        menu_Generator->addAction(action_Prim_s_Algorithm);
        menu_Generator->addAction(action_Back_and_Forth);
        menu_Generator->addAction(action_Backtracker_Algorithm);
        menu_Generator->addAction(action_Braid_Maze);
        menu_Solve->addAction(action_Right_Hand_Rule);
        menu_Solve->addAction(action_Dead_End_Filler);

        retranslateUi(Gui);

        QMetaObject::connectSlotsByName(Gui);
    } // setupUi

    void retranslateUi(QMainWindow *Gui)
    {
        Gui->setWindowTitle(QApplication::translate("Gui", "Maze Solver", 0, QApplication::UnicodeUTF8));
        action_Reset->setText(QApplication::translate("Gui", "&Reset", 0, QApplication::UnicodeUTF8));
        action_Reset->setShortcut(QApplication::translate("Gui", "Ctrl+0", 0, QApplication::UnicodeUTF8));
        action_Dimensions->setText(QApplication::translate("Gui", "&Dimensions...", 0, QApplication::UnicodeUTF8));
        action_Dimensions->setShortcut(QApplication::translate("Gui", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        action_Zoom_In->setText(QApplication::translate("Gui", "&Zoom In", 0, QApplication::UnicodeUTF8));
        action_Zoom_In->setShortcut(QApplication::translate("Gui", "Ctrl++", 0, QApplication::UnicodeUTF8));
        action_Zoom_Out->setText(QApplication::translate("Gui", "&Zoom Out", 0, QApplication::UnicodeUTF8));
        action_Zoom_Out->setShortcut(QApplication::translate("Gui", "Ctrl+-", 0, QApplication::UnicodeUTF8));
        action_Prim_s_Algorithm->setText(QApplication::translate("Gui", "&Prim's Algorithm", 0, QApplication::UnicodeUTF8));
        action_Right_Hand_Rule->setText(QApplication::translate("Gui", "&Right-Hand Rule", 0, QApplication::UnicodeUTF8));
        action_Back_and_Forth->setText(QApplication::translate("Gui", "&Back and Forth", 0, QApplication::UnicodeUTF8));
        action_Backtracker_Algorithm->setText(QApplication::translate("Gui", "Back&tracker Algorithm", 0, QApplication::UnicodeUTF8));
        action_Dead_End_Filler->setText(QApplication::translate("Gui", "&Dead End Filler", 0, QApplication::UnicodeUTF8));
        action_Braid_Maze->setText(QApplication::translate("Gui", "B&raid Maze", 0, QApplication::UnicodeUTF8));
        menu_View->setTitle(QApplication::translate("Gui", "&View", 0, QApplication::UnicodeUTF8));
        menu_Maze->setTitle(QApplication::translate("Gui", "&Maze", 0, QApplication::UnicodeUTF8));
        menu_Generator->setTitle(QApplication::translate("Gui", "&Generate", 0, QApplication::UnicodeUTF8));
        menu_Solve->setTitle(QApplication::translate("Gui", "&Solve", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Gui: public Ui_Gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H

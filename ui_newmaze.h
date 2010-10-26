/********************************************************************************
** Form generated from reading UI file 'newmaze.ui'
**
** Created: Tue Oct 26 15:33:21 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMAZE_H
#define UI_NEWMAZE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *rows;
    QLabel *times;
    QLineEdit *columns;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(207, 101);
        Dialog->setModal(true);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        rows = new QLineEdit(Dialog);
        rows->setObjectName(QString::fromUtf8("rows"));
        rows->setMaxLength(32767);

        gridLayout->addWidget(rows, 1, 0, 1, 1);

        times = new QLabel(Dialog);
        times->setObjectName(QString::fromUtf8("times"));

        gridLayout->addWidget(times, 1, 1, 1, 1);

        columns = new QLineEdit(Dialog);
        columns->setObjectName(QString::fromUtf8("columns"));

        gridLayout->addWidget(columns, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 3);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "New Maze Dimensions", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Enter new maze dimensions:", 0, QApplication::UnicodeUTF8));
        rows->setPlaceholderText(QApplication::translate("Dialog", "rows", 0, QApplication::UnicodeUTF8));
        times->setText(QApplication::translate("Dialog", "X", 0, QApplication::UnicodeUTF8));
        columns->setPlaceholderText(QApplication::translate("Dialog", "columns", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMAZE_H

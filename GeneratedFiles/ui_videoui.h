/********************************************************************************
** Form generated from reading UI file 'videoui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOUI_H
#define UI_VIDEOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_VideoUIClass
{
public:
    QPushButton *closeButton;
    VideoWidget *src1video;
    VideoWidget *desvideo;
    QPushButton *openButton;
    QPushButton *playButton;
    QPushButton *screenButton;
    QPushButton *exportButton;
    QPushButton *setButton;
    VideoWidget *src2video;
    QPushButton *mergeButton;
    QPushButton *blendButton;
    QPushButton *aboutButton;
    QPushButton *maxButton;
    QPushButton *minButton;
    QSlider *playSlider;
    QSlider *leftSlider;
    QSlider *rightSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *widthBox;
    QSpinBox *heightBox;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *pydownBox;
    QSpinBox *pyupBox;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QSpinBox *cxBox;
    QSpinBox *cyBox;
    QSpinBox *cwBox;
    QSpinBox *chBox;
    QSpinBox *mxBox;
    QSpinBox *myBox;
    QPushButton *markButton;
    QDoubleSpinBox *contrastBox;
    QDoubleSpinBox *baBox;
    QDoubleSpinBox *maBox;
    QDoubleSpinBox *brightBox;
    QPushButton *pauseButton;
    QComboBox *rotateBox;
    QComboBox *flipBox;
    QComboBox *colorBox;
    QLabel *label_11;

    void setupUi(QWidget *VideoUIClass)
    {
        if (VideoUIClass->objectName().isEmpty())
            VideoUIClass->setObjectName(QStringLiteral("VideoUIClass"));
        VideoUIClass->resize(1000, 650);
        VideoUIClass->setStyleSheet(QString::fromUtf8("QPushButton:!hover{\n"
"    border-radius: 8px;\n"
"    min-width: 40px;\n"
"	background-color: qlineargradient(spread:reflect, x1:0, y1:0.5, x2:0, y2:1, stop:0.3 rgba(240, 240, 240, 255), stop:1 rgba(125, 125, 125, 255));\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"    border-radius: 8px;\n"
"    min-width: 50px;\n"
"	background-color: qlineargradient(spread:reflect, x1:0, y1:0.5, x2:0, y2:1, stop:0.3 rgba(125, 125, 125, 255), stop:1 rgba(240, 240, 240, 255));\n"
"    border: none;\n"
"}\n"
"\n"
"QSlider::handle:horizontal\n"
"{\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 16px;\n"
"    margin: -2px 0;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::groove:horizontal\n"
"{\n"
"    border: 1px solid #999999;\n"
"	background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"    height: 8px;\n"
"    margin: 2px 0;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::add-pa"
                        "ge:horizontal\n"
"{\n"
"	\n"
"	background-color: rgba(240, 240, 240, 255);\n"
"    height: 8px;\n"
"    margin: 2px 0;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal\n"
"{\n"
"	background-color: rgba(125, 125, 125, 255);\n"
"    height: 8px;\n"
"    margin: 2px 0;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#VideoUIClass{\n"
"	background-color: rgb(30, 30, 30);\n"
"}\n"
"\n"
"#closeButton:!hover{\n"
"	font: 15pt \"\347\255\211\347\272\277\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(30, 30, 30);\n"
"}\n"
"\n"
"#closeButton:hover{\n"
"	font: 15pt \"\347\255\211\347\272\277\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(60, 60, 60);\n"
"}\n"
"\n"
"#maxButton:!hover{\n"
"	font: 15pt \"\347\255\211\347\272\277\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(30, 30, 30);\n"
"}\n"
"\n"
"#maxButton:hover{\n"
"	font: 15pt \"\347\255\211\347\272\277\";\n"
"	color: rgb(255, 255, 255);\n"
"	ba"
                        "ckground-color: rgb(60, 60, 60);\n"
"}\n"
"\n"
"#minButton:!hover{\n"
"	font: 15pt \"\347\255\211\347\272\277\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(30, 30, 30);\n"
"}\n"
"\n"
"#minButton:hover{\n"
"	font: 15pt \"\347\255\211\347\272\277\";\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(60, 60, 60);\n"
"}\n"
"\n"
""));
        closeButton = new QPushButton(VideoUIClass);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(950, 0, 40, 40));
        closeButton->setStyleSheet(QStringLiteral(""));
        closeButton->setFlat(true);
        src1video = new VideoWidget(VideoUIClass);
        src1video->setObjectName(QStringLiteral("src1video"));
        src1video->setGeometry(QRect(10, 50, 480, 300));
        desvideo = new VideoWidget(VideoUIClass);
        desvideo->setObjectName(QStringLiteral("desvideo"));
        desvideo->setGeometry(QRect(510, 50, 480, 300));
        openButton = new QPushButton(VideoUIClass);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(510, 360, 80, 30));
        playButton = new QPushButton(VideoUIClass);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(610, 360, 80, 30));
        screenButton = new QPushButton(VideoUIClass);
        screenButton->setObjectName(QStringLiteral("screenButton"));
        screenButton->setGeometry(QRect(710, 360, 80, 30));
        exportButton = new QPushButton(VideoUIClass);
        exportButton->setObjectName(QStringLiteral("exportButton"));
        exportButton->setGeometry(QRect(810, 360, 80, 30));
        setButton = new QPushButton(VideoUIClass);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setGeometry(QRect(910, 360, 80, 30));
        src2video = new VideoWidget(VideoUIClass);
        src2video->setObjectName(QStringLiteral("src2video"));
        src2video->setGeometry(QRect(10, 410, 380, 230));
        mergeButton = new QPushButton(VideoUIClass);
        mergeButton->setObjectName(QStringLiteral("mergeButton"));
        mergeButton->setGeometry(QRect(410, 450, 80, 30));
        blendButton = new QPushButton(VideoUIClass);
        blendButton->setObjectName(QStringLiteral("blendButton"));
        blendButton->setGeometry(QRect(410, 490, 80, 30));
        aboutButton = new QPushButton(VideoUIClass);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));
        aboutButton->setGeometry(QRect(910, 610, 80, 30));
        maxButton = new QPushButton(VideoUIClass);
        maxButton->setObjectName(QStringLiteral("maxButton"));
        maxButton->setGeometry(QRect(910, 0, 40, 40));
        maxButton->setStyleSheet(QStringLiteral(""));
        maxButton->setFlat(true);
        minButton = new QPushButton(VideoUIClass);
        minButton->setObjectName(QStringLiteral("minButton"));
        minButton->setGeometry(QRect(870, 0, 40, 40));
        minButton->setStyleSheet(QStringLiteral(""));
        minButton->setFlat(true);
        playSlider = new QSlider(VideoUIClass);
        playSlider->setObjectName(QStringLiteral("playSlider"));
        playSlider->setGeometry(QRect(10, 350, 480, 20));
        playSlider->setMaximum(999);
        playSlider->setOrientation(Qt::Horizontal);
        leftSlider = new QSlider(VideoUIClass);
        leftSlider->setObjectName(QStringLiteral("leftSlider"));
        leftSlider->setGeometry(QRect(10, 370, 480, 20));
        leftSlider->setMaximum(999);
        leftSlider->setOrientation(Qt::Horizontal);
        rightSlider = new QSlider(VideoUIClass);
        rightSlider->setObjectName(QStringLiteral("rightSlider"));
        rightSlider->setGeometry(QRect(10, 390, 480, 20));
        rightSlider->setMaximum(999);
        rightSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(VideoUIClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(510, 490, 80, 30));
        label_2 = new QLabel(VideoUIClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(510, 530, 80, 30));
        label_3 = new QLabel(VideoUIClass);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(510, 570, 80, 30));
        label_4 = new QLabel(VideoUIClass);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(510, 610, 80, 30));
        widthBox = new QSpinBox(VideoUIClass);
        widthBox->setObjectName(QStringLiteral("widthBox"));
        widthBox->setGeometry(QRect(610, 570, 80, 30));
        widthBox->setMaximum(5000);
        widthBox->setSingleStep(5);
        heightBox = new QSpinBox(VideoUIClass);
        heightBox->setObjectName(QStringLiteral("heightBox"));
        heightBox->setGeometry(QRect(610, 610, 80, 30));
        heightBox->setMaximum(5000);
        heightBox->setSingleStep(5);
        label_5 = new QLabel(VideoUIClass);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(710, 570, 80, 30));
        label_6 = new QLabel(VideoUIClass);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(710, 610, 80, 30));
        pydownBox = new QSpinBox(VideoUIClass);
        pydownBox->setObjectName(QStringLiteral("pydownBox"));
        pydownBox->setGeometry(QRect(810, 570, 80, 30));
        pydownBox->setMaximum(50);
        pyupBox = new QSpinBox(VideoUIClass);
        pyupBox->setObjectName(QStringLiteral("pyupBox"));
        pyupBox->setGeometry(QRect(810, 610, 80, 30));
        pyupBox->setMaximum(50);
        label_7 = new QLabel(VideoUIClass);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(710, 450, 80, 30));
        label_8 = new QLabel(VideoUIClass);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(710, 490, 80, 30));
        label_9 = new QLabel(VideoUIClass);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(710, 530, 80, 30));
        label_10 = new QLabel(VideoUIClass);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(410, 570, 80, 30));
        cxBox = new QSpinBox(VideoUIClass);
        cxBox->setObjectName(QStringLiteral("cxBox"));
        cxBox->setGeometry(QRect(510, 410, 40, 30));
        cxBox->setMaximum(5000);
        cyBox = new QSpinBox(VideoUIClass);
        cyBox->setObjectName(QStringLiteral("cyBox"));
        cyBox->setGeometry(QRect(550, 410, 40, 30));
        cyBox->setMaximum(5000);
        cwBox = new QSpinBox(VideoUIClass);
        cwBox->setObjectName(QStringLiteral("cwBox"));
        cwBox->setGeometry(QRect(510, 450, 40, 30));
        cwBox->setMaximum(5000);
        chBox = new QSpinBox(VideoUIClass);
        chBox->setObjectName(QStringLiteral("chBox"));
        chBox->setGeometry(QRect(550, 450, 40, 30));
        chBox->setMaximum(5000);
        mxBox = new QSpinBox(VideoUIClass);
        mxBox->setObjectName(QStringLiteral("mxBox"));
        mxBox->setGeometry(QRect(610, 410, 40, 30));
        mxBox->setMaximum(5000);
        myBox = new QSpinBox(VideoUIClass);
        myBox->setObjectName(QStringLiteral("myBox"));
        myBox->setGeometry(QRect(650, 410, 40, 30));
        myBox->setMaximum(5000);
        markButton = new QPushButton(VideoUIClass);
        markButton->setObjectName(QStringLiteral("markButton"));
        markButton->setGeometry(QRect(710, 410, 80, 30));
        contrastBox = new QDoubleSpinBox(VideoUIClass);
        contrastBox->setObjectName(QStringLiteral("contrastBox"));
        contrastBox->setGeometry(QRect(610, 530, 80, 30));
        contrastBox->setMinimum(1);
        contrastBox->setMaximum(3);
        contrastBox->setSingleStep(0.1);
        baBox = new QDoubleSpinBox(VideoUIClass);
        baBox->setObjectName(QStringLiteral("baBox"));
        baBox->setGeometry(QRect(410, 610, 80, 30));
        baBox->setMinimum(0.1);
        baBox->setMaximum(1);
        baBox->setSingleStep(0.1);
        maBox = new QDoubleSpinBox(VideoUIClass);
        maBox->setObjectName(QStringLiteral("maBox"));
        maBox->setGeometry(QRect(610, 450, 80, 30));
        maBox->setMinimum(0.1);
        maBox->setMaximum(1);
        maBox->setSingleStep(0.1);
        brightBox = new QDoubleSpinBox(VideoUIClass);
        brightBox->setObjectName(QStringLiteral("brightBox"));
        brightBox->setGeometry(QRect(610, 490, 80, 30));
        brightBox->setSingleStep(5);
        pauseButton = new QPushButton(VideoUIClass);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setGeometry(QRect(910, 410, 80, 30));
        rotateBox = new QComboBox(VideoUIClass);
        rotateBox->setObjectName(QStringLiteral("rotateBox"));
        rotateBox->setGeometry(QRect(810, 450, 80, 30));
        flipBox = new QComboBox(VideoUIClass);
        flipBox->setObjectName(QStringLiteral("flipBox"));
        flipBox->setGeometry(QRect(810, 490, 80, 30));
        colorBox = new QComboBox(VideoUIClass);
        colorBox->setObjectName(QStringLiteral("colorBox"));
        colorBox->setGeometry(QRect(810, 530, 80, 30));
        label_11 = new QLabel(VideoUIClass);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(410, 410, 80, 30));

        retranslateUi(VideoUIClass);
        QObject::connect(closeButton, SIGNAL(clicked()), VideoUIClass, SLOT(close()));
        QObject::connect(openButton, SIGNAL(clicked()), VideoUIClass, SLOT(Open()));
        QObject::connect(minButton, SIGNAL(clicked()), VideoUIClass, SLOT(showMinimized()));
        QObject::connect(playSlider, SIGNAL(sliderPressed()), VideoUIClass, SLOT(SliderPress()));
        QObject::connect(playSlider, SIGNAL(sliderReleased()), VideoUIClass, SLOT(SliderRelease()));
        QObject::connect(playSlider, SIGNAL(sliderMoved(int)), VideoUIClass, SLOT(SetPos(int)));
        QObject::connect(setButton, SIGNAL(clicked()), VideoUIClass, SLOT(Set()));
        QObject::connect(exportButton, SIGNAL(clicked()), VideoUIClass, SLOT(Export()));
        QObject::connect(playButton, SIGNAL(clicked()), VideoUIClass, SLOT(Play()));
        QObject::connect(pauseButton, SIGNAL(clicked()), VideoUIClass, SLOT(Pause()));
        QObject::connect(markButton, SIGNAL(clicked()), VideoUIClass, SLOT(Mark()));
        QObject::connect(blendButton, SIGNAL(clicked()), VideoUIClass, SLOT(Blend()));
        QObject::connect(mergeButton, SIGNAL(clicked()), VideoUIClass, SLOT(Merge()));
        QObject::connect(leftSlider, SIGNAL(sliderMoved(int)), VideoUIClass, SLOT(Left(int)));
        QObject::connect(rightSlider, SIGNAL(sliderMoved(int)), VideoUIClass, SLOT(Right(int)));

        QMetaObject::connectSlotsByName(VideoUIClass);
    } // setupUi

    void retranslateUi(QWidget *VideoUIClass)
    {
        VideoUIClass->setWindowTitle(QApplication::translate("VideoUIClass", "VideoUI", Q_NULLPTR));
        closeButton->setText(QApplication::translate("VideoUIClass", "X", Q_NULLPTR));
        openButton->setText(QApplication::translate("VideoUIClass", "\346\211\223\345\274\200", Q_NULLPTR));
        playButton->setText(QApplication::translate("VideoUIClass", "\346\222\255\346\224\276/\346\232\202\345\201\234", Q_NULLPTR));
        screenButton->setText(QApplication::translate("VideoUIClass", "\346\210\252\345\233\276", Q_NULLPTR));
        exportButton->setText(QApplication::translate("VideoUIClass", "\345\257\274\345\207\272", Q_NULLPTR));
        setButton->setText(QApplication::translate("VideoUIClass", "\350\256\276\347\275\256", Q_NULLPTR));
        mergeButton->setText(QApplication::translate("VideoUIClass", "\350\247\206\351\242\221\345\220\210\345\271\266", Q_NULLPTR));
        blendButton->setText(QApplication::translate("VideoUIClass", "\350\247\206\351\242\221\350\236\215\345\220\210", Q_NULLPTR));
        aboutButton->setText(QApplication::translate("VideoUIClass", "\345\205\263\344\272\216", Q_NULLPTR));
        maxButton->setText(QApplication::translate("VideoUIClass", "\345\233\227", Q_NULLPTR));
        minButton->setText(QApplication::translate("VideoUIClass", "\344\270\200", Q_NULLPTR));
        label->setText(QApplication::translate("VideoUIClass", "\344\272\256\345\272\246", Q_NULLPTR));
        label_2->setText(QApplication::translate("VideoUIClass", "\345\257\271\346\257\224\345\272\246", Q_NULLPTR));
        label_3->setText(QApplication::translate("VideoUIClass", "\350\276\223\345\207\272\345\256\275\345\272\246", Q_NULLPTR));
        label_4->setText(QApplication::translate("VideoUIClass", "\350\276\223\345\207\272\351\253\230\345\272\246", Q_NULLPTR));
        label_5->setText(QApplication::translate("VideoUIClass", "\351\253\230\346\226\257", Q_NULLPTR));
        label_6->setText(QApplication::translate("VideoUIClass", "\346\213\211\346\231\256\346\213\211\346\226\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("VideoUIClass", "\345\233\276\345\203\217\346\227\213\350\275\254", Q_NULLPTR));
        label_8->setText(QApplication::translate("VideoUIClass", "\345\233\276\345\203\217\351\225\234\345\203\217", Q_NULLPTR));
        label_9->setText(QApplication::translate("VideoUIClass", "\345\233\276\345\203\217\351\242\234\350\211\262", Q_NULLPTR));
        label_10->setText(QApplication::translate("VideoUIClass", "\351\200\217\346\230\216\345\272\246", Q_NULLPTR));
        markButton->setText(QApplication::translate("VideoUIClass", "\346\260\264\345\215\260\350\256\276\347\275\256", Q_NULLPTR));
        pauseButton->setText(QApplication::translate("VideoUIClass", "\346\232\202\345\201\234", Q_NULLPTR));
        rotateBox->clear();
        rotateBox->insertItems(0, QStringList()
         << QApplication::translate("VideoUIClass", "0", Q_NULLPTR)
         << QApplication::translate("VideoUIClass", "90", Q_NULLPTR)
         << QApplication::translate("VideoUIClass", "180", Q_NULLPTR)
         << QApplication::translate("VideoUIClass", "270", Q_NULLPTR)
        );
        flipBox->clear();
        flipBox->insertItems(0, QStringList()
         << QApplication::translate("VideoUIClass", "None", Q_NULLPTR)
         << QApplication::translate("VideoUIClass", "MirrorUpAndDown", Q_NULLPTR)
         << QApplication::translate("VideoUIClass", "MirrorLeftAndRight ", Q_NULLPTR)
         << QApplication::translate("VideoUIClass", "MirrorAll", Q_NULLPTR)
        );
        colorBox->clear();
        colorBox->insertItems(0, QStringList()
         << QApplication::translate("VideoUIClass", "RGB", Q_NULLPTR)
         << QApplication::translate("VideoUIClass", "GRAY", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("VideoUIClass", "\345\233\276\345\203\217\350\243\201\345\211\252->", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoUIClass: public Ui_VideoUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOUI_H

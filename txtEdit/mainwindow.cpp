#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QLabel>
#include <QFontComboBox>
#include <QComboBox>
#include <QToolButton>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置 窗口太小
    this->resize(900, 600);
    //基本控件
    //获取菜单栏
    QMenuBar *menubar = this->menuBar();

    //定义的文件菜单和编辑菜单
    QMenu *fileMenu = menubar->addMenu("文件");
    QMenu *editMenu = menubar->addMenu("编辑");

    //向文件菜单中添加行为
    QAction *newfile = fileMenu->addAction("新建");
    QAction *openfile = fileMenu->addAction("打开");
    QAction *savefile = fileMenu->addAction("保存");
    //添加工具栏
    //通过工具栏添加行为
    QToolBar *toolBar = this->addToolBar("tools");
    toolBar->addAction(newfile);
    toolBar->addSeparator();//分隔符
    toolBar->addAction(openfile);
    toolBar->addSeparator();
    toolBar->addAction(savefile);
    toolBar->addSeparator();
    //图标资源未获取

    //设置字体
    QLabel *fontTypeLb = new QLabel("字体：");
    toolBar->addWidget(fontTypeLb);

    //设置字体框
    QFontComboBox *fontTypeCmb = new QFontComboBox;
    toolBar->addWidget(fontTypeCmb);

    //设置字号
    QLabel *fontSizeLb = new QLabel("字号：");
    toolBar->addWidget(fontSizeLb);

    //设置字号
    QComboBox *fontSizeCmb = new QComboBox;
    toolBar->addWidget(fontSizeCmb);

    int size = 1;
    while (size < 72)
    {
        fontSizeCmb->addItem(QString::number(size));
    }

    //设置加粗按钮
    QToolButton *boldBt = new QToolButton;
    boldBt->setText("B");
    toolBar->addWidget(boldBt);

    QToolButton *itlicBt = new QToolButton;
    itlicBt->setText("I");
    toolBar->addWidget(itlicBt);

    //状态栏
    QStatusBar *statusBar = this->statusBar();
    QLabel *timeLb = new QLabel("时间：");
    statusBar->addWidget(timeLb);

    //设置浮动窗口

    QDockWidget *dockWidget = new QDockWidget();
    this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    QTextEdit *textEdit = new QTextEdit;
    this->setCentralWidget(textEdit);//设置核心控件

}

MainWindow::~MainWindow()
{
    delete ui;
}


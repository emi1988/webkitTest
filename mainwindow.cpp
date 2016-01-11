#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebView>
#include <QDir>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QUrl tempUrl =  QUrl("https://www.tagesschau.de/100sekunden/");
    // QUrl tempUrl =  QUrl("http://media.tagesschau.de/video/100s/2016/0107/TV-100s-1320.webl.h264.mp4");

    QFile file("C:\\Users\\Emi\\Dropbox\\projekts\\qtWebkitTest\\webkitTest\\website2.html");

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QByteArray tempArray =file.readAll();

    //QString testHtmlCode = QString(tempArray);

    file.close();

    QUrl tempUrl = QUrl::fromLocalFile("C:\\Users\\Emi\\Dropbox\\projekts\\qtWebkitTest\\webkitTest\\website2.html");
    //ui->webView->load(tempUrl);

    //QString testHtmlCode = "<html lang='de-de'><head><title>Test</title></head><body><video src='http://media.tagesschau.de/video/100s/2016/0108/TV-100s-1219.podm.h264.mp4' width='320' height='240' autoplay></video></body></html>";

    QString testHtmlCode = "<html lang='de-de'><head><title>Test</title></head>\n\n\n<body>\n\n<video src='http://media.tagesschau.de/video/100s/2016/0107/TV-100s-1422.webxl.h264.mp4' width='320' height='240' autoplay>\n\n</video>\n\n</body></html>\n";
    //QUrl baseUrl = QUrl::fromLocalFile(QDir::current().absoluteFilePath("dummy.html"));
    ui->webView->setHtml(testHtmlCode);
    ui->webView->show();


}

MainWindow::~MainWindow()
{
    delete ui;
}

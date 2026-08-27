#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <windows.h>
#include <securitybaseapi.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    std::system("reg delete HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost");
}
void MainWindow::Experimental_FP()
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v BranchName /t REG_SZ /d CanaryChannel /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIBranch /t REG_SZ /d Dev /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UITargetVersion /t REG_DWORD /d 0 /f");
}
void MainWindow::Experimental_26H1()
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v BranchName /t REG_SZ /d Dev /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIBranch /t REG_SZ /d Dev /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UITargetVersion /t REG_DWORD /d 28000 /f");
}
void MainWindow::Experimental_26H2()
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v BranchName /t REG_SZ /d Dev /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIBranch /t REG_SZ /d Dev /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UITargetVersion /t REG_DWORD /d 26200 /f");
}
void MainWindow::Beta()
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v BranchName /t REG_SZ /d Beta /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIBranch /t REG_SZ /d Beta /f");
}
void MainWindow::ReleasePreview()
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v BranchName /t REG_SZ /d ReleasePreview /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIBranch /t REG_SZ /d ReleasePreview /f");
}
void MainWindow::doEnroll()
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v ContentType /t REG_SZ /d Mainline /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v Ring /t REG_SZ /d External /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v RingId /t REG_DWORD /d 11 /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIRing /t REG_SZ /d External /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIContentType /t REG_SZ /d Mainline /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v EulaAccepted /t REG_DWORD /d 1 /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\OneSettings /f /t REG_DWORD /v FlightSettingsVersion /d 2");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\OneSettings /f /t REG_DWORD /v IsBuildUnsupported /d 0");
}
void MainWindow::on_pushButton_7_clicked()
{
    MainWindow::reset();
}
void MainWindow::on_pushButton_8_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_clicked()
{
    MainWindow::Experimental_FP();
    MainWindow::doEnroll();
    QMessageBox::information(this, "OfflineInsiderEnroll", "Successfully enrolled channel!");
}


void MainWindow::on_pushButton_2_clicked()
{
    MainWindow::Experimental_26H1();
    MainWindow::doEnroll();
    QMessageBox::information(this, "OfflineInsiderEnroll", "Successfully enrolled channel!");
}


void MainWindow::on_pushButton_3_clicked()
{
    MainWindow::Experimental_26H2();
    MainWindow::doEnroll();
    QMessageBox::information(this, "OfflineInsiderEnroll", "Successfully enrolled channel!");
}


void MainWindow::on_pushButton_5_clicked()
{
    MainWindow::Beta();
    MainWindow::doEnroll();
    QMessageBox::information(this, "OfflineInsiderEnroll", "Successfully enrolled channel!");
}


void MainWindow::on_pushButton_6_clicked()
{
    MainWindow::ReleasePreview();
    MainWindow::doEnroll();
    QMessageBox::information(this, "OfflineInsiderEnroll", "Successfully enrolled channel!");
}


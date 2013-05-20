#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Set the UI components.
    first_band = ui->cmbBand1;
    second_band = ui->cmbBand2;
    multiplier = ui->cmbMultiplier;
    tolerance = ui->cmbTolerance;
    result = ui->lblResult;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::set_result(const QString &result_str) {
    QString formatted_result = "<html><head/><body><p><span style='font-size:16pt; font-weight:600;'>" +
            result_str +
            "</span></p></body></html>";
    result->setText(formatted_result);
}

void MainWindow::on_cmbBand1_currentTextChanged(const QString &arg1) {
    set_result(arg1);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Set the UI components.
    first_band = ui->cmbBand1;
    second_band = ui->cmbBand2;
    multiplier = ui->cmbMultiplier;
    tolerance = ui->cmbTolerance;
    result = ui->lblResult;

    // Load defaults.
    bands.push_back("black");
    bands.push_back("black");
    bands.push_back("black");
    bands.push_back("gold");

    vector<const char*> tmp_bands;
    for (size_t i = 0; i < bands.size(); ++i) {
        tmp_bands.push_back(bands[i].toStdString().c_str());
    }
    set_result(resistance_calc.pretty_print(resistance_calc.calculate(bands), bands[bands.size() - 1].toStdString().c_str()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::set_result(const QString &result_str) {
    QString formatted_result = "<span style='font-size:16pt; font-weight:600;'>" +
            result_str +
            "</span>";
    result->setText(formatted_result);
}

void MainWindow::set_band(int index, const QString &color) {
    /*// Create a copy.
    vector<const char*> tmp_bands;
    for (size_t i = 0; i < bands.size(); ++i) {
        if (i != index) {
            tmp_bands.push_back(bands[i]);
        } else {
            tmp_bands.push_back(color.toLower().toStdString().c_str());
        }
    }

    // Repopulate.
    bands.clear();
    for (size_t i = 0; i < tmp_bands.size(); ++i) {
        bands.push_back(tmp_bands[i]);
    }*/
    bands[index] = color.toLower();

    cout << bands[index].toStdString() << endl;
    set_result(resistance_calc.pretty_print(resistance_calc.calculate(bands), bands[bands.size() - 1].toStdString().c_str()));
}

void MainWindow::on_cmbBand1_currentTextChanged(const QString &value) {
    set_band(0, value);
}

void MainWindow::on_cmbBand2_currentTextChanged(const QString &value) {
    cout << value.toLower().toStdString().c_str() << endl;
    set_band(1, value);
}

void MainWindow::on_cmbMultiplier_currentTextChanged(const QString &value) {
    set_band(2, value);
}

void MainWindow::on_cmbTolerance_currentTextChanged(const QString &value) {
    set_band(3, value);
}

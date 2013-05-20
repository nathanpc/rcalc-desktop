#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QString>

#include <vector>
#include <iostream>
#include <cstring>

#include "resistance_calc.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    private:
        Ui::MainWindow *ui;

        QComboBox *first_band;
        QComboBox *second_band;
        QComboBox *multiplier;
        QComboBox *tolerance;
        QLabel *result;

        std::vector<QString> bands;
        ResistanceCalc resistance_calc;

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        void set_result(const QString &result_str);
        void set_band(int index, const QString &color);

    private slots:
        void on_cmbBand1_currentTextChanged(const QString &value);
        void on_cmbBand2_currentTextChanged(const QString &value);
        void on_cmbMultiplier_currentTextChanged(const QString &value);
        void on_cmbTolerance_currentTextChanged(const QString &value);
};

#endif // MAINWINDOW_H

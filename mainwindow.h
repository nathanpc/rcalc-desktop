#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QString>

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

        ResistanceCalc calc;

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        void set_result(const QString &result_str);
private slots:
        void on_cmbBand1_currentTextChanged(const QString &arg1);
};

#endif // MAINWINDOW_H

#ifndef PERSONADIALOG_H
#define PERSONADIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "persona.h"

namespace Ui {
class PersonaDialog;
}

class PersonaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonaDialog(QWidget *parent = nullptr);
    ~PersonaDialog();
    Persona *persona() const;
    void set_datos(QString nom, QString ape, QString tel, QString email);
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::PersonaDialog *ui;
    Persona *m_persona;
    bool validar_email(QString email);
};

#endif // PERSONADIALOG_H

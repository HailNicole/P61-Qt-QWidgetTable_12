#include "personadialog.h"
#include "ui_personadialog.h"

PersonaDialog::PersonaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonaDialog)
{
    ui->setupUi(this);
}

PersonaDialog::~PersonaDialog()
{
    delete ui;
}

void PersonaDialog::on_buttonBox_accepted()
{
    QString nombre = ui->inNombre->text();
    QString apellido = ui->inApellido->text();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();
    if(!validar_email(email)){
        QMessageBox::information(this,"Correo","Correo Inválido");
        return;
    }
    this->m_persona = new Persona(nombre, apellido, telefono, email);
    accept();
}

void PersonaDialog::on_buttonBox_rejected()
{
    reject();
}

bool PersonaDialog::validar_email(QString email)
{
  QRegExp pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  return pattern.exactMatch(email);
}
void PersonaDialog::set_datos(QString nom, QString ape, QString tel, QString email)
{
    ui->inNombre->setText(nom);
    ui->inApellido->setText(ape);
    ui->inTelefono->setText(tel);
    ui->inEmail->setText(email);
}

Persona *PersonaDialog::persona() const
{
    return m_persona;
}


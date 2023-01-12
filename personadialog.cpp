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


    if(!validar_texto(nombre) || !validar_texto(apellido) || !validar_tel(telefono) || !validar_email(email)){
        QMessageBox::information(this, "Error", "Datos Erróneos o Incompletos");
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
    if(email.isEmpty()){
        return false;
    }

      QRegExp pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
      return pattern.exactMatch(email);
}

bool PersonaDialog::validar_tel(QString telefono)
{
    if(telefono.isEmpty() || telefono.length()!=10){
        return false;
    }

    QChar aux[10];

    for(int i = 0; i < 10; i++)
    {
        aux[i] = telefono[i];
    }

    for(int i = 0; i < 10; i++)
    {
        if(aux[i].isDigit()==0){
            return false;
            break;
        }
    }
    return true;
}

bool PersonaDialog::validar_texto(QString texto)
{
    if(texto.isEmpty()){
        return false;
    }
    int tam = texto.length();
    QChar aux[tam];

    for(int i = 0; i < tam; i++)
    {
        aux[i] = texto[i];
    }

    for(int i = 0; i < tam; i++)
    {
        if(aux[i].isDigit()==1){
            return false;
            break;
        }
    }
    return true;
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


void PersonaDialog::on_inNombre_editingFinished()
{
    QString nombre = ui->inNombre->text();
    if(!validar_texto(nombre)){
        ui->inNombre->setStyleSheet("background-color: rgb(255, 105, 180)");
    }
    else{
        ui->inNombre->setStyleSheet("background-color: rgb(153, 193, 241)");
    }
}


void PersonaDialog::on_inApellido_editingFinished()
{
    QString apellido = ui->inApellido->text();
    if(!validar_texto(apellido)){
        ui->inApellido->setStyleSheet("background-color: rgb(255, 105, 180)");
    }
    else{
        ui->inApellido->setStyleSheet("background-color: rgb(153, 193, 241)");
    }
}


void PersonaDialog::on_inTelefono_editingFinished()
{
    QString telefono = ui->inTelefono->text();
    if(!validar_tel(telefono)){
        ui->inTelefono->setStyleSheet("background-color: rgb(255, 105, 180)");
    }
    else{
        ui->inTelefono->setStyleSheet("background-color: rgb(153, 193, 241)");
    }
}


void PersonaDialog::on_inEmail_editingFinished()
{
    QString email = ui->inEmail->text();
    if(!validar_email(email)){
        ui->inEmail->setStyleSheet("background-color: rgb(255, 105, 180)");
    }
    else{
        ui->inEmail->setStyleSheet("background-color: rgb(153, 193, 241)");
    }
}

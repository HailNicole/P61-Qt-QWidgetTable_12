#include "persona.h"

Persona::Persona(QObject *parent)
    : QObject{parent}
{

}

Persona::Persona(const QString &nombre, const QString &apellido, const QString &telefono, const QString &email) :
    m_nombre(nombre),
    m_apellido(apellido),
    m_telefono(telefono),
    m_email(email)
{}

const QString &Persona::nombre() const
{
    return m_nombre;
}

const QString &Persona::apellido() const
{
    return m_apellido;
}

const QString &Persona::telefono() const
{
    return m_telefono;
}

const QString &Persona::email() const
{
    return m_email;
}

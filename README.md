# 🔐 Sistema de Control de Acceso -- Panel Electrónico Integrado

## 📌 Descripción del Proyecto

Este proyecto consiste en la **modernización e integración de un sistema
de control de acceso** basado en panel eléctrico, actualmente compuesto
por múltiples módulos independientes.

La nueva solución propone el diseño de una **tarjeta electrónica (PCB)
unificada**, que centraliza el control del sistema mediante un
microcontrolador **ESP32**, mejorando la mantenibilidad, escalabilidad y
facilidad de configuración.

------------------------------------------------------------------------

## 🎯 Objetivos

-   Integrar múltiples módulos en una sola tarjeta electrónica
-   Simplificar el mantenimiento del sistema
-   Permitir configuración remota (sin abrir el panel)
-   Mantener la funcionalidad del sistema actual
-   Mejorar la confiabilidad y orden del sistema

------------------------------------------------------------------------

## ⚙️ Sistema Actual

### 🔧 Componentes

-   Sensores de proximidad
-   Módulos de relés independientes
-   Fuente de poder
-   Batería de 12V
-   Temporizador / reloj
-   Receptor inalámbrico + control remoto
-   Cerraduras magnéticas

### 🔄 Funcionamiento

-   Al detectar una persona, se desbloquea la puerta
-   Si no se abre en 5 segundos, se vuelve a bloquear
-   Si se abre, se bloquea al cerrarse nuevamente
-   Horario de funcionamiento: **9:00 AM -- 5:00 PM**
    -   Dentro del horario: entrada y salida permitidas
    -   Fuera del horario: solo salida permitida
-   Control remoto permite:
    -   Bloquear puertas
    -   Liberar puertas
    -   Enviar señal de emergencia

------------------------------------------------------------------------

## 🚀 Nueva Solución Propuesta

### 🧠 Arquitectura

El sistema será rediseñado utilizando:

-   🧩 **PCB diseñada en KiCad**
-   ⚡ **Microcontrolador ESP32**
-   🔌 Alimentación de **12V DC**
-   🔋 Sistema de respaldo con batería
-   🔁 Sistema de carga automática de batería

------------------------------------------------------------------------

## 🔌 Entradas y Salidas

### 📥 Entradas

-   2 × Sensores de proximidad (contacto seco)
-   3 × Señales de control remoto:
    -   Bloquear
    -   Liberar
    -   Emergencia

### 📤 Salidas

-   4 × Relés:
    -   Control de cerradura (bloqueo/desbloqueo)
    -   Señal de emergencia (luz externa)
    -   Señal a centro de monitoreo
    -   Salida adicional configurable

------------------------------------------------------------------------

## 🔄 Lógica de Funcionamiento

El nuevo sistema mantiene la lógica actual:

-   Detección de persona → desbloqueo de puerta
-   Temporizador de 5 segundos si no se abre
-   Bloqueo automático al cerrar la puerta
-   Restricción por horario:
    -   Dentro del horario: acceso completo
    -   Fuera del horario: solo salida

------------------------------------------------------------------------

## 🎮 Control Remoto

### Funcionalidades requeridas:

-   🔒 Bloqueo total (anula sensores) (C)
-   🔓 Liberación total (anula sensores) (A)
-   🚨 Señal de emergencia: (B-D) ambos
    -   Activación de luz externa
    -   Notificación al centro de monitoreo

> ⚠️ Se evaluará una alternativa más moderna al sistema actual de
> control remoto y receptor inalámbrico.

------------------------------------------------------------------------

## 🔋 Sistema de Energía

-   Alimentación principal: **12V DC**
-   Batería de respaldo:
    -   Se activa automáticamente ante fallo eléctrico
-   Carga de batería:
    -   Automática cuando hay alimentación AC
    -   Protección contra sobrecarga

------------------------------------------------------------------------

## 💻 Configuración y Mantenimiento

-   Configuración del sistema mediante **ESP32**
-   Acceso desde laptop (posibles opciones):
    -   Interfaz web
    -   Conexión serial / USB
    -   WiFi

### Parámetros configurables:

-   Horario de funcionamiento
-   Tiempos de desbloqueo
-   Estados de relés
-   Configuración de entradas/salidas

------------------------------------------------------------------------

## 🛠️ Herramientas de Desarrollo

-   🧩 **KiCad** -- Diseño de PCB
-   💻 **Arduino IDE** -- Programación del ESP32
-   📝 **Visual Studio Code** -- Edición de código y control de
    versiones

------------------------------------------------------------------------

## 📈 Mejoras Clave

-   Integración total del hardware en una sola PCB
-   Reducción de cableado y puntos de falla
-   Configuración sin abrir el panel
-   Mayor claridad para mantenimiento técnico
-   Escalabilidad futura

------------------------------------------------------------------------

## 🧪 Estado del Proyecto

🚧 En desarrollo

-   [x] Definición de requerimientos
-   [ ] Diseño esquemático en KiCad
-   [ ] Diseño de PCB
-   [ ] Desarrollo de firmware ESP32
-   [ ] Pruebas funcionales
-   [ ] Implementación en campo

------------------------------------------------------------------------

## 🔮 Posibles Mejoras Futuras

-   Aplicación web para monitoreo en tiempo real
-   Registro de eventos (logs)
-   Integración con sistemas de seguridad centralizados
-   Notificaciones remotas
-   Uso de tecnologías IoT

------------------------------------------------------------------------

## 📄 Licencia

Este proyecto es de uso interno / privado.

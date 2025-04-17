# Diseño de un Sistema de Medición de Corriente para Microcontroladores con Transmisión Inalámbrica

### Autores
- **Karla Vanessa Ruíz González** — Universidad Industrial de Santander  
- **Óscar Andrés Meza Ortiz** — Universidad Industrial de Santander  

---

## Descripción del Proyecto

Este proyecto tiene como objetivo el diseño de un sistema electrónico operado por batería, que permita medir la corriente de operación de un microcontrolador en sus distintos modos de funcionamiento: modo normal y modo de sueño profundo. La medición se realiza de forma periódica, alternando entre ambos modos, lo que permite analizar el comportamiento energético del microcontrolador a lo largo del tiempo.

El sistema está diseñado para ofrecer precisión y bajo burden voltage en la medición, permitiendo detectar corrientes tanto en el orden de los miliamperios como de los microamperios. Para ello, se implementa un sistema de cambio de rango (manual o automático) que adapta la medición al nivel de corriente detectado. La señal medida es amplificada y enviada a un conversor analógico-digital, y finalmente, los datos se transmiten inalámbricamente a través de un microcontrolador ESP32.

---

## Estructura del Repositorio

- `docs/` – Informe final y presentación del proyecto.
- `hardware/` – Esquemáticos y diseño de PCB del circuito.
- `firmware/` – Código del microcontrolador para la transmisión inalámbrica.
- `simulacion/` – Resultados de simulaciones y archivos de Proteus.
- `app_inventor/` – Archivos del diseño de la app móvil para visualizar los datos.

---

## Transmisión de Datos

El sistema emplea un ESP32 para la transmisión inalámbrica de las mediciones. Estas son recibidas por una aplicación desarrollada en [App Inventor](https://appinventor.mit.edu/), permitiendo visualizar en tiempo real el comportamiento de la corriente en el microcontrolador evaluado.

---

## Estado del Proyecto

Este trabajo corresponde al diseño completo y simulado del sistema de medición. No se realizó una implementación física, pero se desarrollaron y documentaron todos los bloques funcionales, respaldados por simulaciones, selección de componentes y diseño de una aplicación móvil funcional.

---


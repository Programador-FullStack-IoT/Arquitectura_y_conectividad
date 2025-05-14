![alt text](<../E - Assets/ISPC.jpg>)
        
<h1> 👨‍🏫 Profesor </h1>
        <table align="center">
          <thead>
            <tr>
              <th>Nombre y Apellido</th>
              <th>Usuario en GitHub</th>
              <th>GitHub</th>
            </tr>
          </thead>
          <tbody>
           <tr>
              <td> Jorge Elias Morales </td>
              <td> JorEl057 </td>
              <td>
                <a href="https://github.com/JorEl057">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
        </table>
  </dd>
  <dd>
<dl>

<br>

<h1> 👩‍💻👨🏼‍💻 Integrantes 👩‍💻👨🏼‍💻 </h1>
        <table align="center">
          <thead>
            <tr>
              <th>Nombre y Apellido</th>
              <th>Usuario en GitHub</th>
              <th>GitHub</th>
            </tr>
          </thead>
          <tbody>
            <tr>
              <td> Fernando Gimenez Coria </td>
              <td> FerCbr </td>
              <td>
                <a href="https://github.com/FerCbr">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
            <tr>
            <tr>
              <td> Nicolás Barrionuevo </td>
              <td> NicolasB-27 </td>
              <td>
                <a href="https://github.com/NicolasB-27">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
            <tr>
              <td> Macarena Aylen Carballo </td>
              <td> MacarenaAC </td>
              <td>
                <a href="https://github.com/MacarenaAC">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
           <tr>
              <td> Raul Jara </td>
              <td> r-j28 </td>
              <td>
                <a href="https://github.com/r-j28">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
           <tr>
              <td> Diego Ezequiel Ares </td>
              <td>  diegote7 </td>
              <td>
                <a href="https://github.com/diegote7">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
           <tr>
              <td> Juan Diego González Antoniazzi </td>
              <td> JDGA1997 </td>
              <td>
                <a href="https://github.com/JDGA1997">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
        </table>
  </dd>
  <dd>
<dl>

# Comunicación por Radiofrecuencia LoRa con ESP32

Este proyecto implementa un sistema de transmisión y recepción de datos ambientales mediante comunicación LoRa entre dos nodos basados en ESP32. Un nodo emisor mide temperatura y humedad usando un sensor DHT11, y otro nodo receptor recibe estos datos y activa un relé si se supera un umbral de temperatura.

## Arquitectura del Sistema

- **Nodo Emisor (TX):**
  - Lee temperatura y humedad del sensor DHT11.
  - Envía los datos vía LoRa en formato de texto.
  
- **Nodo Receptor (RX):**
  - Recibe los datos enviados por LoRa.
  - Analiza la temperatura.
  - Activa o desactiva un relé (simulado con un LED) en función del valor recibido.

## Hardware Requerido

### Para cada nodo ESP32:
- 1 x ESP32 DevKit v1
- 1 x Módulo LoRa SX1278 (frecuencia: 433 MHz)
- Cables Dupont
- Fuente de alimentación USB o batería

### Nodo TX adicional:
- 1 x Sensor DHT11

### Nodo RX adicional:
- 1 x LED o módulo relé conectado al pin 27

## Conexiones de Pines

### LoRa (común para ambos nodos)
| Módulo LoRa | ESP32 |
|-------------|-------|
| MISO        | GPIO 19 |
| MOSI        | GPIO 23 |
| SCK         | GPIO 18 |
| NSS (SS)    | GPIO 5  |
| RESET       | GPIO 14 |
| DIO0        | GPIO 26 |

### Sensor DHT11 (solo TX)
| DHT11 | ESP32 |
|-------|-------|
| DATA  | GPIO 4 |

### Relé o LED (solo RX)
| Relé/LED | ESP32 |
|----------|-------|
| IN/Anodo | GPIO 27 |

## Librerías Utilizadas

- [`LoRa`](https://github.com/sandeepmistry/arduino-LoRa) - Para comunicación LoRa
- [`DHT`](https://github.com/adafruit/DHT-sensor-library) - Para leer el sensor DHT11

Instálalas desde el Library Manager de Arduino o `platformio.ini` si usas PlatformIO.

## Funcionamiento

### Nodo Emisor (`lora_nodo_tx`)
1. Inicializa el sensor DHT11.
2. Lee temperatura y humedad.
3. Envía los datos por LoRa en formato:  
   `Temp:31.0 Hum:60.0`
4. Repite cada 5 segundos.

### Nodo Receptor (`lora_nodo_rx`)
1. Espera paquetes LoRa.
2. Cuando recibe un mensaje, lo analiza.
3. Si la temperatura es superior a **30 °C**, activa el relé (LED ON).
4. Si es igual o menor, lo desactiva (LED OFF).

## Resultados Esperados
En el Monitor Serial del receptor se verá: 
Mensaje recibido: Temp:29.5,Hum:45.2 
El relay o LED se activa cuando la temperatura es mayor a 30 °C. 

📁 Estructura del Proyecto 
LoRa_Proyecto/ 

│ 

├── src/ 

│   ├── main_tx.cpp      ← Código del nodo transmisor 

│   └── main_rx.cpp      ← Código del nodo receptor 

│ 

├── lib/                 ← Librerías gestionadas por PlatformIO 

├── docs/                ← Diagramas, presentación y datasheets 

├── platformio.ini       ← Configuración del entorno 

└── README.md            ← Este archivo 


## Ejemplo de Salida Serial

**Nodo TX:**


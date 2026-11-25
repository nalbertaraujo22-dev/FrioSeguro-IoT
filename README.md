# ❄️ FrioSeguro IoT — Sistema Inteligente de Monitoramento Térmico

![Status](https://img.shields.io/badge/Status-Conclu%C3%ADdo-brightgreen)
![Hardware](https://img.shields.io/badge/Hardware-Arduino%20Uno%20%2B%20DHT22-blue)
![Interface](https://img.shields.io/badge/Dashboard-Dark%20Mode%20Web-06b6d4)
![Licença](https://img.shields.io/badge/Licen%C3%A7a-MIT-lightgrey)

O **FrioSeguro IoT** é uma solução de telemetria e alerta preventivo projetada para proteger insumos refrigerados e medicamentos termolábeis contra falhas de climatização. O sistema combina monitoramento embarcado contínuo com sinalização local (visor LCD, LEDs e alarme sonoro) e um painel web de supervisão em tempo real.

---

## 🎯 Problema & Impacto Comercial
Pequenos comércios, farmácias e clínicas perdem estoques inteiros quando freezers ou câmaras frias falham fora do horário comercial. O **FrioSeguro IoT** elimina a dependência de verificação manual ao detectar desvios térmicos em menos de **5 segundos**, reduzindo perdas financeiras e garantindo conformidade sanitária.

---

## 📊 Parâmetros Operacionais

| Faixa de Temperatura | Estado do Sistema | Sinalização Local (Hardware) | Ação no Gateway |
| :--- | :--- | :--- | :--- |
| **2.0°C a 8.0°C** | 🟢 **NORMAL** | LED Verde aceso / LCD exibe `NORMAL` | Registro contínuo no log CSV |
| **< 2.0°C ou > 8.0°C** | 🔴 **CRÍTICO** | LED Vermelho + Buzzer 1kHz + LCD `ALERTA!` | Alerta visual pulsante no Dashboard |

---

## 🏗️ Arquitetura do Projeto

```text
FrioSeguro-IoT/
├── firmware/
│   └── frioseguro.ino             # Código C++ (Arduino Uno + DHT22 + LCD I2C + Buzzer)
├── gateway/
│   └── dashboard.html             # Painel de telemetria Dark-Mode com gráficos em tempo real
├── dados/
│   └── historico_temperaturas.csv # Base histórica de auditoria térmica (24h)
└── README.md                      # Documentação técnica do projeto

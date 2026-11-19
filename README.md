# ❄️ FrioSeguro IoT

Sistema inteligente de monitoramento térmico e alerta preventivo para conservação de insumos refrigerados em pequenos comércios locais.

## 📋 Sobre o Projeto
Este projeto foi desenvolvido como atividade de extensão curricular para a disciplina **Aplicações de Cloud, IoT e Indústria 4.0 em Python (ARA0058)**[cite: 1]. A solução visa prevenir prejuízos financeiros e riscos sanitários causados por falhas de refrigeração ou portas de freezers deixadas abertas, oferecendo uma alternativa de baixo custo e fácil visualização remota para microempreendedores[cite: 14, 15].

## ⚙️ Arquitetura e Tecnologias Utilizadas
* **Hardware e Simulação (Arduino Uno / Wokwi):** Leitura contínua de temperatura (sensor DHT22) e status de abertura de porta (chave magnética simulada), com alarme sonoro local imediato (Buzzer) caso a temperatura ultrapasse **-10 °C**[cite: 15].
* **Middleware / Gateway (Python 3):** Script responsável por capturar os dados via comunicação Serial, aplicar regras de negócio para detecção de anomalias e enviar pacotes via protocolo HTTP REST[cite: 15].
* **Cloud IoT (ThingSpeak):** Armazenamento em nuvem e exibição de gráficos em tempo real para acompanhamento remoto pelo comerciante[cite: 15].

## 📂 Estrutura do Repositório
* `PROJETO DE EXTENSÃO.zip` — Arquivos da montagem eletrônica (`diagram.json`) e código-fonte do microcontrolador (`sketch.ino`) para simulação no Wokwi[cite: 19].
* `frioseguro_gateway.py` — Script em Python que realiza a ponte entre os dados do Arduino e a nuvem ThingSpeak[cite: 19].
* `Relatorio_Extensao_FrioSeguro_IoT-v2.docx` — Roteiro de Extensão completo com diagnóstico, planejamento, detalhamento técnico e avaliação de resultados[cite: 15, 19].

## 👨‍💻 Autor
* **Nalbert Alves de Araújo** — Matrícula: `202303700628`[cite: 15]28

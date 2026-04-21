# Sistema de Irrigação Inteligente com ESP32 🌱

## 📌 Descrição
Este projeto simula um sistema de irrigação automatizado utilizando ESP32.

O sistema monitora:
- Umidade do ambiente (DHT22)
- Luminosidade (LDR)
- Nutrientes simulados (botões NPK)

Com base nessas informações, o sistema decide automaticamente ligar ou desligar a irrigação (relé).

---

## ⚙️ Componentes utilizados
- ESP32
- Sensor DHT22 (umidade)
- Sensor LDR (luminosidade)
- Módulo relé
- Botões (simulação de nutrientes NPK)

---

## 🧠 Lógica do sistema
A irrigação é ativada quando:
- Umidade < 50%
- pH estimado entre 5 e 7
- Pelo menos 2 nutrientes estão OK

---

## 🔌 Arquivos do projeto
- `sketch.ino` → código principal
- `diagram.json` → circuito no Wokwi
- Imagem do circuito → representação visual

---

## ▶️ Simulação
Projeto desenvolvido utilizando a plataforma Wokwi.

---

## 👨‍💻 Autor
Thiago Perazzo

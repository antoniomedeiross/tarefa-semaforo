# Descrição dos Projetos

Este repositório contém dois programas para o microcontrolador **Raspberry Pi Pico W**, utilizando a biblioteca **Pico SDK**. Ambos os programas implementam controle de **LEDs** usando temporizadores.

---

## 📌 1. Semáforo com Temporizador Periódico

### 📖 **Descrição**
Este programa simula um **semáforo** utilizando três LEDs (**vermelho, amarelo e verde**), alternando entre eles a cada **3 segundos** de forma cíclica.

### ⚙ **Funcionamento**
1. 🔴 **O LED vermelho acende primeiro.**
2. 🟡 **Após 3 segundos, ele apaga e o LED amarelo acende.**
3. 🟢 **Após mais 3 segundos, o LED amarelo apaga e o LED verde acende.**
4. 🔄 **O ciclo se repete continuamente.**
5. 🖥 **O programa imprime mensagens na porta serial a cada segundo.**

### 🛠 **Componentes Utilizados**
- 🖥 **Raspberry Pi Pico W**
- 🔴🟡🟢 **3 LEDs (vermelho, amarelo e verde)**
- ⚡ **3 Resistores de 330Ω**

---

## 📌 2. Temporizador de Um Disparo com Botão

### 📖 **Descrição**
Este programa controla três LEDs (**vermelho, amarelo e verde**) acionados por um **botão**. Quando o botão é pressionado, os LEDs acendem e apagam em sequência após um tempo determinado.

### ⚙ **Funcionamento**
1. 🎛 **O usuário pressiona o botão, ativando todos os LEDs.**
2. 🔴 **Após 3 segundos, o LED vermelho apaga.**
3. 🟡 **Após 6 segundos, o LED amarelo apaga.**
4. 🟢 **Após 9 segundos, o LED verde apaga.**
5. 🔄 **O botão só pode ser pressionado novamente após todos os LEDs serem desligados.**

### 🛠 **Componentes Utilizados**
- 🖥 **Raspberry Pi Pico W**
- 🔴🟡🟢 **3 LEDs (vermelho, amarelo e verde)**
- ⚡ **3 Resistores de 330Ω**
- 🎛 **1 Pushbutton**

---

## 💻 **Ambiente de Desenvolvimento**
- 📝 **Linguagem de Programação:** C
- 🏗 **IDE:** Visual Studio Code com suporte ao **Pico SDK**
- 🖥 **Simulador:** Wokwi (opcional)
- ⚙ **Compilação utilizando CMake**

---

## 🚀 **Instruções de Compilação e Execução**
```bash
# Configure o ambiente de desenvolvimento para Raspberry Pi Pico W
# Compile os códigos utilizando CMake e Ninja
# Suba o firmware gerado para o Pico
# Conecte ao terminal serial para visualizar as mensagens de depuração
```

---



# 📚 Cadastro de Alunos com Vector em C++

Este é um projeto simples feito em C++ com o objetivo de praticar o uso da estrutura `vector`, entrada de dados com validação e organização modular do código. O sistema permite:

- Cadastrar alunos (nome e duas notas)
- Calcular e armazenar a média automaticamente
- Listar todos os alunos cadastrados
- Sair do programa com confirmação

---

## 🛠 Funcionalidades

- ✅ Leitura de opções com validação de entrada (`lerOpcao`)
- ✅ Cadastro de até 10 alunos
- ✅ Cálculo automático da média do aluno
- ✅ Armazenamento dos alunos em um `std::vector`
- ✅ Listagem clara e organizada de todos os alunos

---

## 📌 Estruturas usadas

- `struct aluno`: armazena nome, nota1, nota2 e média
- `vector<aluno>`: para guardar dinamicamente a lista de alunos

---

## 🧠 Conceitos explorados

- Vectores (`std::vector`)
- Funções reutilizáveis
- Laços de repetição e condições
- Entrada segura com validação
- Organização de código limpo e legível

---

## 🚀 Como executar

1. Copie o conteúdo do código para um compilador C++ como:
   - Code::Blocks
   - Dev-C++
   - OnlineGDB
   - ou terminal usando `g++`

2. Compile e execute:

```bash
g++ main.cpp -o cadastro_aluno
./cadastro_aluno

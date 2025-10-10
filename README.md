# Milestone2 Pipex

Este projeto faz parte do currículo da scola 42 e tem como objetivo **reproduzir o comportamento do shell** ao lidar com redirecionamentos e pipes.

O programa deve executar dois comandos em sequência, recebendo um arquivo de entrada, dois comandos e um arquivo de saída — assim como acontece no bash com:  

```bash
< infile cmd1 | cmd2 > outfile
```
## 🔧 Regras do Projeto

Input válido:
```bash
./pipex infile "cmd1" "cmd2" outfile
```

O programa deve reproduzir exatamente o comportamento do bash:

- Ler o infile.
- Executar cmd1.
- Encadear a saída de cmd1 para cmd2 com pipe.
- Escrever a saída final no outfile.
- Erros devem ser tratados corretamente: parâmetros inválidos, comandos inexistentes ou não executáveis, falhas no fork/pipe/open, etc.

##  🚀 Minha Solução

A minha implementação da parte obrigatória segue os passos abaixo:

1. Validação da entrada
- Uso a função input_invalid para garantir que o input esteja no formato correto.
- Caso contrário, imprimo a mensagem adequada e encerro o programa.

2. Criação do Pipe
- Chamo pipe() e verifico o retorno.
- Caso falhe (-1), imprimo perror e encerro.

3. Primeiro fork (cmd1)
- Crio um processo filho com fork() e armazeno seu retorno em pid1.
- Caso fork falhe, imprimo perror e encerro.
- Se for o processo filho, preparo os FDs e executo cmd1.

4. Execução do cmd1
- Redireciono stdin para ler de infile (fd 0 → new_fd).
- Redireciono stdout para escrever no pipe_fd[1].
- Trato a string do comando com split.
- Se for caminho absoluto (/bin/ls), chamo cmd_bar.
- Se for relativo (ls), chamo cmd_not_bar para buscar o caminho no PATH.
- Verifico se é executável. Caso contrário, imprimo erro e encerro.

5. Executo com execve.
- Segundo fork (cmd2)
- Após o processo filho do cmd1 morrer, faço outro fork() para cmd2.
- Redireciono stdin para ler do pipe (pipe_fd[0]).
- Redireciono stdout para outfile.
- Busco ou verifico o caminho do comando e executo.

6. Finalização
- Fecho todos os FDs na main.
- Uso waitpid para garantir que os processos rodem em ordem.
- Retorno o status do segundo comando, como no bash.

## 📈 Estratégia

Minha solução é focada em reproduzir fielmente o comportamento do bash usando as funções do sistema:

- pipe() para criar a comunicação entre processos.
- fork() para criar subprocessos independentes para cada comando.
- dup2() para redirecionar entrada e saída.
- execve() para executar os comandos.
- waitpid() para sincronizar os processos.

A lógica de separar o tratamento de caminhos absolutos e relativos permite maior clareza e controle na execução dos comandos.

## 🛠️ Como usar

Compilar:
```bash
make
```

Executar:
```bash
./pipex infile "cmd1" "cmd2" outfile
```

Exemplo:
```bash
./pipex infile "cat" "grep hello" outfile
```

Equivalente no bash:
```bash
< infile cat | grep hello > outfile
```

## 📚 O que aprendi

- Como funciona o pipe e a comunicação entre processos no Unix.
- Criação de processos com fork() e sincronização com waitpid().
- Redirecionamento de entrada/saída com dup2().
- Execução de binários com execve().
- Como tratar caminhos absolutos e relativos de forma robusta.

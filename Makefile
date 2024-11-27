# Variáveis
CC = gcc                           # Compilador
CFLAGS = -Wall -Wextra -g          # Flags de compilação
SRC = src                          # Diretório de código-fonte
INCLUDE = include                  # Diretório de cabeçalhos
BUILD = build                      # Diretório de saída dos binários
EXEC = main                        # Nome do executável principal

# Alvo padrão: compilar tudo
all: $(BUILD)/$(EXEC)

# Regra para compilar o executável principal
$(BUILD)/$(EXEC): $(SRC)/*.c $(INCLUDE)/*.h
	mkdir -p $(BUILD)                # Criar o diretório build, se não existir
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ $(SRC)/*.c

# Regra para executar os testes
test: $(SRC)/*.c $(INCLUDE)/*.h tests/*.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(BUILD)/test tests/*.c $(SRC)/*.c
	./$(BUILD)/test

# Limpar arquivos compilados
clean:
	rm -rf $(BUILD)/*

# Ajuda para mostrar as regras disponíveis
help:
	@echo "Comandos disponíveis:"
	@echo "  make           - Compila o projeto principal"
	@echo "  make test      - Compila e executa os testes"
	@echo "  make clean     - Remove arquivos compilados"

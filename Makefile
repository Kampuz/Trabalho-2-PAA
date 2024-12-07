#Variáveis
CC = gcc						# Compilador
CFLAGS = -Wall -Wextra -g		# Flags de compilação
SRC = src						# Diretório de código-fonte
INCLUDE = include				# Diretório de cabeçalhos
BUILD = build					# Diretório de saída dos binários
TESTS = tests					# Nome do executável princial

# Alvo padrão: compilar tudo
all: $(BUILD)/main

# Regra para compilar o executável principal
$(BUILD)/main: $(SRC)/main.c $(SRC)/*.c $(INCLUDE)/*.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ $(SRC)/*.c

# Regra para executar os testes
test: $(TESTS)/*.c $(SRC)/*.c $(INCLUDE)/*.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(BUILD)/test $(TESTS)/*.c $(SRC)/*.c
	./$(BUILD)/test

# Limpar arquivos compilados
clean:
	rm -rf $(BUILD)/*

help:
	@echo "Comandos disponíveis:"
	@echo " make		- Compila o projeto principal"
	@echo " make test	- Compila e executa os testes"
	@echo " make clean	- Remove arquivos compilados"
CC=eosio-cpp
Contract=tictactoe

all:
	@echo "Compiling ..."
	# $(CC) -abigen -I include -R resource -contract $(Contract) -o $(Contract).wasm src/$(Contract).cpp
	$(CC) -abigen -I contract -R contract -contract $(Contract) -o $(Contract).wasm contract/$(Contract).cpp

clean:
	rm *.wasm
	rm *.abi

deploy:
	cleos set contract $(Contract) . $(Contract).wasm $(Contract).abi
	
CC=eosio-cpp
Contract=toyhaus
Account=$(Contract)

all:
	@echo "Compiling ..."
	$(CC) -abigen -I include -I /usr/opt/eosio.cdt/1.7.0/include/eosiolib/core/eosio/ -R resource -contract $(Contract) -o $(Contract).wasm src/$(Contract).cpp

clean:
	rm *.wasm
	rm *.abi

deploy:
	cleos set contract $(Account) . $(Contract).wasm $(Contract).abi

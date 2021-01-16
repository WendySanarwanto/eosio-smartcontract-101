CC=eosio-cpp
Contract=toyhaus

all:
	@echo "Compiling ..."
	$(CC) -abigen -I include -R resource -contract $(Contract) -o $(Contract).wasm src/$(Contract).cpp

clean:
	rm *.wasm
	rm *.abi

deploy:
	cleos set contract $(Contract) . $(Contract).wasm $(Contract).abi
	
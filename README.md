# eosio-smartcontract-101

An EOSIO project artifact of [Smartcontract 101](https://training.eos.io/courses/take/smart-contracts-101) course's project. 

# Setup

1. __TODO__


## Building sample contract

The source code for the sample smartcontract is at `contract/talk.cpp` within the IDE. To compile the contract, run this in a terminal:

```
eosio-cpp contract/<contract's name>.cpp

```

This will produce `<contract's name>.abi` and `<contract's name>.wasm`.

## Installing the contract

Run this in a terminal:

```
cleos create account eosio <contract's name> EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
cleos set code <contract account's name> <contract's name>.wasm
cleos set abi <contract account's name> <contract's name>.abi

```

## Creating users and using the contract

Run this in a terminal:
```
cleos create account eosio bob EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
cleos create account eosio jane EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV
cleos push action <contract 's name> <contract action's name> '[param1, param2, param3, "param4"]' -p bob
cleos push action <contract 's name> <contract action's name> '[param1, param2, param3, "param4"]' -p jane
cleos push action <contract 's name> <contract action's name> '[param1, param2, param3, "param4"]' -p bob

```

## Listing the messages

Run this in a terminal:
```
cleos get table <contract's name> '' <table's name>

```
